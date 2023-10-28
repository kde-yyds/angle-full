#!/usr/bin/python3
# Copyright 2016 The ANGLE Project Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.
#
# gen_angle_format_table.py:
#  Code generation for ANGLE format map.
#  NOTE: don't run this script directly. Run scripts/run_code_generation.py.
#

import angle_format
import json
import math
import os
import pprint
import re
import sys

template_autogen_h = """// GENERATED FILE - DO NOT EDIT.
// Generated by {script_name} using data from {data_source_name}
//
// Copyright 2020 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// ANGLE format enumeration.

#ifndef LIBANGLE_RENDERER_FORMATID_H_
#define LIBANGLE_RENDERER_FORMATID_H_

#include <cstdint>

namespace angle
{{

enum class FormatID
{{
{angle_format_enum}
}};

constexpr uint32_t kNumANGLEFormats = {num_angle_formats};

}}  // namespace angle

#endif  // LIBANGLE_RENDERER_FORMATID_H_
"""

template_autogen_inl = """// GENERATED FILE - DO NOT EDIT.
// Generated by {script_name} using data from {data_source_name}
//
// Copyright 2020 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// ANGLE Format table:
//   Queries for typed format information from the ANGLE format enum.

#include "libANGLE/renderer/Format.h"

#include "image_util/copyimage.h"
#include "image_util/generatemip.h"
#include "image_util/loadimage.h"

namespace angle
{{

static constexpr rx::FastCopyFunctionMap::Entry BGRAEntry = {{angle::FormatID::R8G8B8A8_UNORM,
                                                             CopyBGRA8ToRGBA8}};
static constexpr rx::FastCopyFunctionMap BGRACopyFunctions = {{&BGRAEntry, 1}};
static constexpr rx::FastCopyFunctionMap NoCopyFunctions;

const Format gFormatInfoTable[] = {{
    // clang-format off
    {{ FormatID::NONE, GL_NONE, GL_NONE, nullptr, NoCopyFunctions, nullptr, nullptr, GL_NONE, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, false, false, false, false, gl::VertexAttribType::InvalidEnum }},
{angle_format_info_cases}    // clang-format on
}};

// static
FormatID Format::InternalFormatToID(GLenum internalFormat)
{{
    switch (internalFormat)
    {{
{angle_format_switch}
    }}
}}

const Format *GetFormatInfoTable()
{{
    return gFormatInfoTable;
}}
}}  // namespace angle
"""


def ceil_int(value, mod):
    assert mod > 0 and value > 0, 'integer modulation should be larger than 0'
    return (value + mod - 1) // mod


def is_depth_stencil(angle_format):
    if not 'channels' in angle_format or not angle_format['channels']:
        return False
    return 'd' in angle_format['channels'] or 's' in angle_format['channels']


def get_component_suffix(angle_format):
    if angle_format['componentType'] == 'float':
        return 'F'
    if angle_format['componentType'] == 'int' or angle_format['componentType'] == 'snorm':
        return 'S'
    return ""


def get_channel_struct(angle_format):
    if 'bits' not in angle_format or angle_format['bits'] is None:
        return None
    if 'BLOCK' in angle_format['id']:
        return None
    if 'VERTEX' in angle_format['id']:
        return None
    if 'EXTERNAL' in angle_format['id']:
        return None

    bits = angle_format['bits']

    if 'channelStruct' in angle_format:
        return angle_format['channelStruct']

    struct_name = ''
    component_suffix = get_component_suffix(angle_format)

    for channel in angle_format['channels']:
        if channel == 'r':
            struct_name += 'R{}'.format(bits['R'])
        if channel == 'g':
            struct_name += 'G{}'.format(bits['G'])
        if channel == 'b':
            struct_name += 'B{}'.format(bits['B'])
        if channel == 'a':
            struct_name += 'A{}'.format(bits['A'])
        if channel == 'l':
            struct_name += 'L{}'.format(bits['L'])
        if channel == 'd':
            struct_name += 'D{}'.format(bits['D']) + component_suffix
        if channel == 's':
            struct_name += 'S{}'.format(bits['S'])
        if channel == 'x':
            struct_name += 'X{}'.format(bits['X'])

    if not is_depth_stencil(angle_format):
        struct_name += component_suffix

    return struct_name


def get_mip_generation_function(angle_format):
    channel_struct = get_channel_struct(angle_format)
    if is_depth_stencil(angle_format) or channel_struct == None \
            or "BLOCK" in angle_format["id"] or "VERTEX" in angle_format["id"]:
        return 'nullptr'
    return 'GenerateMip<' + channel_struct + '>'


def get_color_read_write_component_type(angle_format):
    component_type_map = {
        'uint': 'GLuint',
        'int': 'GLint',
        'unorm': 'GLfloat',
        'snorm': 'GLfloat',
        'float': 'GLfloat'
    }
    return component_type_map[angle_format['componentType']]


def get_color_read_function(angle_format):
    channel_struct = get_channel_struct(angle_format)
    if channel_struct == None:
        return 'nullptr'

    if is_depth_stencil(angle_format):
        return 'ReadDepthStencil<' + channel_struct + '>'

    read_component_type = get_color_read_write_component_type(angle_format)
    return 'ReadColor<' + channel_struct + ', ' + read_component_type + '>'


def get_color_write_function(angle_format):
    channel_struct = get_channel_struct(angle_format)
    if channel_struct == None:
        return 'nullptr'

    if is_depth_stencil(angle_format):
        return 'WriteDepthStencil<' + channel_struct + '>'

    write_component_type = get_color_read_write_component_type(angle_format)
    return 'WriteColor<' + channel_struct + ', ' + write_component_type + '>'


format_entry_template = """    {{ FormatID::{id}, {glInternalFormat}, {fboImplementationInternalFormat}, {mipGenerationFunction}, {fastCopyFunctions}, {colorReadFunction}, {colorWriteFunction}, {namedComponentType}, {R}, {G}, {B}, {A}, {L}, {D}, {S}, {pixelBytes}, {componentAlignmentMask}, {isBlock}, {isFixed}, {isScaled}, {isSRGB}, {isYUV}, {vertexAttribType} }},
"""


def get_named_component_type(component_type):
    if component_type == "snorm":
        return "GL_SIGNED_NORMALIZED"
    elif component_type == "unorm":
        return "GL_UNSIGNED_NORMALIZED"
    elif component_type == "float":
        return "GL_FLOAT"
    elif component_type == "uint":
        return "GL_UNSIGNED_INT"
    elif component_type == "int":
        return "GL_INT"
    elif component_type == "none":
        return "GL_NONE"
    else:
        raise ValueError("Unknown component type for " + component_type)


def get_component_alignment_mask(channels, bits):
    if channels == None or bits == None:
        return "std::numeric_limits<GLuint>::max()"
    bitness = bits[channels[0].upper()]
    for channel in channels:
        if channel not in "rgba":
            return "std::numeric_limits<GLuint>::max()"
        # Can happen for RGB10A2 formats.
        if bits[channel.upper()] != bitness:
            return "std::numeric_limits<GLuint>::max()"
    component_bytes = (int(bitness) >> 3)

    if component_bytes == 1:
        return "0"
    elif component_bytes == 2:
        return "1"
    elif component_bytes == 4:
        return "3"
    else:
        # Can happen for 4-bit RGBA.
        return "std::numeric_limits<GLuint>::max()"


def get_vertex_attrib_type(format_id):

    has_u = "_U" in format_id
    has_s = "_S" in format_id
    has_float = "_FLOAT" in format_id
    has_fixed = "_FIXED" in format_id
    has_r8 = "R8" in format_id
    has_r16 = "R16" in format_id
    has_r32 = "R32" in format_id
    has_r10 = "R10" in format_id
    has_vertex = "VERTEX" in format_id

    if has_fixed:
        return "Fixed"

    if has_float:
        return "HalfFloat" if has_r16 else "Float"

    if has_r8:
        return "Byte" if has_s else "UnsignedByte"

    if has_r10:
        if has_vertex:
            return "Int1010102" if has_s else "UnsignedInt1010102"
        else:
            return "Int2101010" if has_s else "UnsignedInt2101010"

    if has_r16:
        return "Short" if has_s else "UnsignedShort"

    if has_r32:
        return "Int" if has_s else "UnsignedInt"

    # Many ANGLE formats don't correspond with vertex formats.
    return "InvalidEnum"


def bool_str(cond):
    return "true" if cond else "false"


def json_to_table_data(format_id, json, angle_to_gl):

    table_data = ""

    parsed = {
        "id": format_id,
        "fastCopyFunctions": "NoCopyFunctions",
    }

    for k, v in sorted(json.items()):
        parsed[k] = v

    if "glInternalFormat" not in parsed:
        parsed["glInternalFormat"] = angle_to_gl[format_id]

    if "fboImplementationInternalFormat" not in parsed:
        parsed["fboImplementationInternalFormat"] = parsed["glInternalFormat"]

    if "componentType" not in parsed:
        parsed["componentType"] = angle_format.get_component_type(format_id)

    if "channels" not in parsed:
        parsed["channels"] = angle_format.get_channels(format_id)

    if "bits" not in parsed:
        parsed["bits"] = angle_format.get_bits(format_id)

    # Derived values.
    parsed["mipGenerationFunction"] = get_mip_generation_function(parsed)
    parsed["colorReadFunction"] = get_color_read_function(parsed)
    parsed["colorWriteFunction"] = get_color_write_function(parsed)

    for channel in angle_format.kChannels:
        if parsed["bits"] != None and channel in parsed["bits"]:
            parsed[channel] = parsed["bits"][channel]
        else:
            parsed[channel] = "0"

    parsed["namedComponentType"] = get_named_component_type(parsed["componentType"])

    if format_id == "B8G8R8A8_UNORM":
        parsed["fastCopyFunctions"] = "BGRACopyFunctions"

    is_block = format_id.endswith("_BLOCK")

    pixel_bytes = 0
    if is_block:
        assert 'blockPixelBytes' in parsed, \
            'Compressed format %s requires its block size to be specified in angle_format_data.json' % \
                format_id
        pixel_bytes = parsed['blockPixelBytes']
    else:
        sum_of_bits = 0
        for channel in angle_format.kChannels:
            sum_of_bits += int(parsed[channel])
        pixel_bytes = ceil_int(sum_of_bits, 8)
    parsed["pixelBytes"] = pixel_bytes
    parsed["componentAlignmentMask"] = get_component_alignment_mask(parsed["channels"],
                                                                    parsed["bits"])
    parsed["isBlock"] = bool_str(is_block)
    parsed["isFixed"] = bool_str("FIXED" in format_id)
    parsed["isScaled"] = bool_str("SCALED" in format_id)
    parsed["isSRGB"] = bool_str("SRGB" in format_id)
    # For now we only look for the 'PLANE' or 'EXTERNAL' substring in format string. Expand this condition
    # when adding support for YUV formats that have different identifying markers.
    parsed["isYUV"] = bool_str("PLANE" in format_id or "EXTERNAL" in format_id)

    parsed["vertexAttribType"] = "gl::VertexAttribType::" + get_vertex_attrib_type(format_id)

    return format_entry_template.format(**parsed)


# For convenience of the Vulkan backend, place depth/stencil formats first.  This allows
# depth/stencil format IDs to be placed in only a few bits.
def sorted_ds_first(all_angle):
    ds_sorted = []
    color_sorted = []
    external_sorted = []
    for format_id in sorted(all_angle):
        if format_id == 'NONE':
            continue
        if 'EXTERNAL' in format_id:
            external_sorted.append(format_id)
        elif format_id[0] == 'D' or format_id[0] == 'S':
            ds_sorted.append(format_id)
        else:
            color_sorted.append(format_id)

    return ds_sorted + color_sorted + external_sorted


def parse_angle_format_table(all_angle, json_data, angle_to_gl):
    table_data = ''
    for format_id in sorted_ds_first(all_angle):
        assert (format_id != 'NONE')
        format_info = json_data[format_id] if format_id in json_data else {}
        table_data += json_to_table_data(format_id, format_info, angle_to_gl)

    return table_data


def gen_enum_string(all_angle):
    enum_data = '    NONE'
    for format_id in sorted_ds_first(all_angle):
        assert (format_id != 'NONE')
        enum_data += ',\n    ' + format_id
    return enum_data


case_template = """        case {gl_format}:
            return FormatID::{angle_format};
"""


def gen_map_switch_string(gl_to_angle):
    switch_data = ''
    for gl_format in sorted(gl_to_angle.keys()):
        angle_format = gl_to_angle[gl_format]
        switch_data += case_template.format(gl_format=gl_format, angle_format=angle_format)
    switch_data += "        default:\n"
    switch_data += "            return FormatID::NONE;"
    return switch_data


def main():

    # auto_script parameters.
    if len(sys.argv) > 1:
        inputs = ['angle_format.py', 'angle_format_data.json', 'angle_format_map.json']
        outputs = ['Format_table_autogen.cpp', 'FormatID_autogen.h']

        if sys.argv[1] == 'inputs':
            print(','.join(inputs))
        elif sys.argv[1] == 'outputs':
            print(','.join(outputs))
        else:
            print('Invalid script parameters')
            return 1
        return 0

    gl_to_angle = angle_format.load_forward_table('angle_format_map.json')
    angle_to_gl = angle_format.load_inverse_table('angle_format_map.json')
    data_source_name = 'angle_format_data.json'
    json_data = angle_format.load_json(data_source_name)
    all_angle = angle_to_gl.keys()

    angle_format_cases = parse_angle_format_table(all_angle, json_data, angle_to_gl)
    switch_data = gen_map_switch_string(gl_to_angle)
    output_cpp = template_autogen_inl.format(
        script_name=os.path.basename(sys.argv[0]),
        angle_format_info_cases=angle_format_cases,
        angle_format_switch=switch_data,
        data_source_name=data_source_name)
    with open('Format_table_autogen.cpp', 'wt') as out_file:
        out_file.write(output_cpp)
        out_file.close()

    enum_data = gen_enum_string(all_angle)
    num_angle_formats = len(all_angle)
    output_h = template_autogen_h.format(
        script_name=os.path.basename(sys.argv[0]),
        angle_format_enum=enum_data,
        data_source_name=data_source_name,
        num_angle_formats=num_angle_formats)
    with open('FormatID_autogen.h', 'wt') as out_file:
        out_file.write(output_h)
        out_file.close()

    return 0


if __name__ == '__main__':
    sys.exit(main())