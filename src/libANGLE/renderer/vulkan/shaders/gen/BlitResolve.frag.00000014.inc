// GENERATED FILE - DO NOT EDIT.
// Generated by gen_vk_internal_shaders.py.
//
// Copyright 2018 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// shaders/gen/BlitResolve.frag.00000014.inc:
//   Pre-generated shader for the ANGLE Vulkan back-end.

#pragma once
constexpr uint8_t kBlitResolve_frag_00000014[] = {
    0x1f,0x8b,0x08,0x00,0x00,0x00,0x00,0x00,0x02,0xff,0x7d,0x94,0xdb,0x4b,0x54,0x51,
    0x14,0xc6,0xf7,0x5c,0x9c,0xd1,0x6e,0x1a,0x36,0x6a,0x1a,0x61,0x99,0xd1,0x0d,0x11,
    0xac,0x08,0x22,0xa1,0x87,0x28,0x70,0xcc,0xcb,0xa8,0x59,0x96,0xe3,0x6d,0x22,0x49,
    0x2d,0x74,0x2a,0x29,0xe9,0x62,0x89,0x95,0x14,0x53,0x99,0x3e,0x04,0x65,0xbd,0xf6,
    0xf7,0x45,0x17,0x08,0x5a,0x6b,0x9f,0xdf,0x8e,0x95,0x0f,0x0d,0x6c,0xce,0x59,0xdf,
    0xfa,0xd6,0xe5,0xdb,0x67,0xad,0x49,0xc4,0x9b,0xd2,0xce,0xc5,0xdc,0x16,0x57,0xee,
    0xbe,0xb8,0xe8,0xb7,0xd3,0xc5,0x05,0x89,0x9e,0xef,0xab,0x9d,0xf8,0x2a,0x5c,0xae,
    0x7b,0x20,0x7f,0x6e,0xb0,0x2f,0x3f,0x77,0x63,0x74,0xa2,0x30,0x9b,0x9f,0x2b,0x16,
    0x66,0xc6,0x27,0xa7,0xf2,0x85,0xf9,0xdb,0xb7,0x66,0x8b,0xc2,0xdd,0xea,0x52,0x3e,
    0xe6,0x7c,0x36,0x97,0x6d,0x99,0x2b,0x4e,0xb4,0x1c,0x3f,0xd1,0xaa,0xb9,0x76,0xb8,
    0x84,0xcf,0xa9,0xbe,0x4a,0xa9,0x91,0x94,0xa7,0x9e,0xe9,0xd1,0xc9,0x19,0xe7,0x31,
    0xe7,0xb2,0x72,0xf2,0x72,0xaa,0x84,0xab,0xbe,0xb4,0x79,0xdf,0xa6,0x39,0xe5,0xad,
    0xd2,0xd7,0x88,0xf8,0x17,0x5c,0x99,0xab,0xa5,0xd7,0x26,0x9e,0x01,0x8b,0x81,0x95,
    0x1b,0x2c,0x0e,0x56,0x65,0xb0,0x04,0x58,0x9d,0xc1,0x92,0x60,0x7b,0x0c,0x56,0x06,
    0xd6,0x68,0xb0,0x14,0xd8,0x01,0x83,0xa5,0xc1,0x0e,0x19,0xac,0x1c,0xec,0x98,0xc1,
    0x2a,0xc0,0x5a,0xbd,0xae,0xc4,0xdf,0xfe,0x54,0x63,0x16,0x8d,0x35,0xd8,0x5d,0xf2,
    0xdc,0x8f,0xbe,0x60,0xef,0x33,0x76,0x6e,0x93,0x3f,0x87,0x3f,0xe4,0xcb,0x93,0x6f,
    0xad,0x3a,0xb2,0xc7,0x36,0xf1,0xc7,0xe0,0xeb,0x9d,0x55,0x4b,0x54,0xdc,0xdb,0x09,
    0x7f,0x37,0x71,0xdf,0x47,0xc2,0x6b,0x55,0xed,0xb5,0xc2,0x4f,0xa3,0x3d,0x8e,0xbd,
    0x1d,0x3b,0xe9,0x39,0x49,0xf9,0xd6,0x51,0x2e,0xc5,0x4f,0x63,0x57,0x82,0x65,0xc4,
    0xce,0x90,0x2b,0xd8,0x35,0xd8,0xfa,0xdb,0x2b,0x5f,0x3a,0xdc,0x63,0x38,0x19,0x4e,
    0x8a,0x67,0x8d,0x39,0x5a,0xaf,0x8e,0xfb,0xac,0xa5,0x9e,0xda,0xbb,0xc1,0x8e,0x52,
    0xaf,0x9e,0x7a,0xca,0x6f,0xc0,0x97,0x36,0xfe,0x50,0x3f,0xd8,0xcd,0xf8,0x95,0x7f,
    0x10,0xbe,0xd6,0xdb,0x25,0xaa,0x0f,0xc3,0x53,0xfb,0xc8,0xa6,0xb8,0x36,0xbe,0x77,
    0xb0,0xdb,0x89,0xd5,0x3c,0x1d,0xcc,0x5b,0x8a,0x3e,0x3b,0x98,0xf9,0x84,0xef,0xb7,
    0xc2,0x75,0xe2,0x8b,0xb9,0x7f,0x7f,0xc1,0xd6,0x1c,0x17,0x79,0xef,0x24,0x87,0xda,
    0x5d,0x60,0xf5,0xd2,0x5b,0x0f,0xbc,0x5e,0xb0,0x1e,0x78,0x6a,0xe7,0xc0,0x1a,0xa4,
    0x62,0x3f,0x39,0x42,0x9f,0x83,0x7c,0x4f,0x8d,0x1d,0xa6,0xa7,0x0c,0xb1,0xc3,0xec,
    0x65,0xe8,0x73,0x84,0xbb,0xf8,0x5f,0x9f,0xa3,0xbc,0x8f,0x90,0x43,0xed,0x31,0x53,
    0xbf,0x80,0x4f,0xe7,0xe7,0x26,0xf9,0x74,0x7e,0x4e,0xca,0x7e,0xc4,0x79,0x77,0xd4,
    0xfc,0x21,0x88,0xee,0xdf,0x19,0x66,0x6d,0x96,0x79,0xea,0x11,0x54,0xef,0xab,0x08,
    0xe6,0x0c,0x76,0x07,0x4c,0x7b,0xea,0x16,0x4c,0xbf,0xe5,0x5d,0xb8,0xea,0x3b,0x2b,
    0x98,0xce,0xc1,0x3d,0x66,0xa5,0x9e,0xfc,0xca,0x9b,0x07,0x5f,0x22,0xee,0x3e,0xb1,
    0xf3,0x26,0xee,0x01,0x71,0x8d,0x26,0x6e,0x01,0xfc,0x29,0x71,0x0f,0x89,0x5d,0x20,
    0x4e,0xe7,0xe8,0x11,0x71,0xcd,0xc4,0xa9,0xee,0xc7,0xe0,0x5f,0x85,0xa3,0xb3,0xf5,
    0x04,0x4c,0x67,0xeb,0xbb,0xdc,0xc0,0x32,0xda,0x7e,0x09,0x5f,0x7d,0x8b,0x72,0x96,
    0xb9,0x97,0x45,0xa3,0xf9,0x19,0x35,0x9d,0xcf,0x97,0xf4,0xd8,0x12,0x78,0xaf,0x58,
    0xda,0xd3,0x07,0xb0,0xc0,0xfb,0x29,0x39,0x42,0x2e,0x7d,0x7e,0x13,0x96,0xf2,0x3e,
    0xc1,0x29,0x23,0x66,0xd1,0x68,0x78,0x8e,0x86,0x36,0xa3,0xe1,0x05,0x78,0xd0,0xf0,
    0x12,0x2c,0x68,0x28,0x19,0x0d,0xea,0x5b,0x91,0x53,0xa2,0xee,0x8a,0xd1,0xf0,0x8a,
    0xda,0x31,0xa3,0xe1,0x35,0x78,0xd0,0xf0,0x11,0x2c,0xf0,0x54,0x43,0xc8,0x55,0x32,
    0x1a,0x36,0xe0,0x2c,0x13,0xb3,0x62,0x34,0xbc,0x41,0x43,0xbb,0xd1,0xf0,0x16,0x3c,
    0x68,0x78,0x07,0x16,0x34,0xac,0x1b,0x0d,0xea,0x5b,0x95,0xb3,0x4e,0xdd,0x55,0xbf,
    0x87,0x51,0xdd,0x35,0x6a,0x6f,0x98,0x9d,0xd0,0x1e,0x03,0x77,0xdd,0xf4,0xf8,0x19,
    0x5e,0x89,0xb8,0x55,0xfa,0xe9,0xf4,0x73,0x1b,0xed,0xb6,0xda,0xba,0xc7,0x7d,0xec,
    0xf0,0x80,0xf4,0xd7,0xef,0x9f,0x11,0xa7,0xcf,0xcc,0xe5,0x65,0x74,0x0d,0x9a,0xb9,
    0xbc,0x02,0x1e,0xe6,0x79,0x88,0xba,0x8a,0x5f,0x12,0x4c,0x77,0xea,0x2a,0xf9,0x86,
    0xcc,0xb7,0xb8,0x06,0xee,0xfc,0x3d,0x25,0xfc,0x7f,0xd5,0x35,0xf2,0xea,0xee,0x8e,
    0xb3,0xd3,0xda,0x8f,0xee,0xf3,0x75,0xb0,0x3e,0xf2,0xea,0x5e,0x4f,0x81,0x87,0xbc,
    0x7a,0xcf,0xd3,0xe0,0xce,0xef,0x46,0xf4,0xff,0x33,0x03,0xae,0x75,0xf2,0xd8,0xbf,
    0xe5,0xf6,0x4e,0xc9,0xf9,0x03,0xab,0x2c,0x84,0x1c,0x9c,0x08,0x00,0x00
};

// Generated from:
//
// #version 450 core
//
// #extension GL_GOOGLE_include_directive : require
//
// #extension GL_ARB_shader_stencil_export : require
//
// layout(set = 0, binding = 0)uniform texture2D depth;
//
// layout(set = 0, binding = 1)uniform utexture2D stencil;
//
// layout(set = 0, binding = 2)uniform sampler blitSampler;
//
// #line 1 "shaders/src/BlitResolve.inc"
//
// layout(push_constant)uniform PushConstants {
//
//             vec2 offset;
//     vec2 stretch;
//     vec2 invSrcExtent;
//     int srcLayer;
//     int samples;
//     float invSamples;
//
//     int outputMask;
//
//     bool flipX;
//     bool flipY;
//     bool rotateXY;
// } params;
//
//         vec2 getSrcImageCoords()
// {
//
//             vec2 srcImageCoords = vec2(gl_FragCoord . xy);
//
//     srcImageCoords *= params . stretch;
//
//     srcImageCoords -= params . offset;
//
//     if(params . flipX)
//         srcImageCoords . x = - srcImageCoords . x;
//     if(params . flipY)
//         srcImageCoords . y = - srcImageCoords . y;
//     if(params . rotateXY)
//         srcImageCoords . xy = srcImageCoords . yx;
//
//     return srcImageCoords;
// }
//
// #line 123 "shaders/src/BlitResolve.frag"
//
// void main()
// {
//             vec2 srcImageCoords = getSrcImageCoords();
//
//     gl_FragDepth = texture(sampler2D(depth, blitSampler), srcImageCoords * params . invSrcExtent). x;
//
//     gl_FragStencilRefARB = int(texture(usampler2D(stencil, blitSampler), srcImageCoords * params . invSrcExtent). x);
//
// }
