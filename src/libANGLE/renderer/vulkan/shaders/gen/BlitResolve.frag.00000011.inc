// GENERATED FILE - DO NOT EDIT.
// Generated by gen_vk_internal_shaders.py.
//
// Copyright 2018 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// shaders/gen/BlitResolve.frag.00000011.inc:
//   Pre-generated shader for the ANGLE Vulkan back-end.

#pragma once
constexpr uint8_t kBlitResolve_frag_00000011[] = {
    0x1f,0x8b,0x08,0x00,0x00,0x00,0x00,0x00,0x02,0xff,0x5d,0x93,0xeb,0x4b,0x94,0x41,
    0x14,0xc6,0x67,0xf7,0x5d,0x77,0xb5,0x9b,0x86,0xad,0x9a,0x46,0x58,0x66,0x74,0x43,
    0x04,0x2b,0x82,0x48,0xe8,0x43,0x14,0xb8,0xa6,0xb6,0x6a,0x66,0xd6,0x66,0xee,0x96,
    0x82,0xa9,0xad,0x9b,0x58,0x49,0x61,0x2a,0x85,0x95,0xe4,0x07,0xa3,0xac,0xff,0xa0,
    0xbf,0x2f,0xba,0x40,0xd0,0x39,0xf3,0xfe,0x46,0x0e,0x2e,0xcc,0xce,0x9c,0x67,0x9e,
    0x73,0x79,0xde,0x73,0x26,0x4a,0xb6,0x65,0x9c,0x4b,0xb8,0x3d,0xae,0xda,0x7d,0x77,
    0xf1,0xef,0xa0,0x4b,0x0a,0x12,0xef,0x5b,0xf5,0x4e,0xee,0x6a,0x5c,0xbe,0x7f,0xb8,
    0x70,0x6d,0x64,0xb0,0x30,0x3f,0x39,0x5e,0x2c,0x95,0x0b,0xf3,0x95,0xd2,0xcc,0xc4,
    0xd4,0x74,0xa1,0xb4,0x38,0x37,0x5b,0xae,0x08,0x77,0xaf,0x4b,0x7b,0x9f,0xeb,0xb9,
    0x7c,0xae,0x63,0xbe,0x52,0xec,0x38,0x7f,0xa1,0x53,0x63,0x1d,0x70,0x91,0x8f,0xa9,
    0x77,0xb5,0x2e,0xe3,0x52,0xb2,0xeb,0x7a,0x32,0x3e,0x35,0xe3,0x3c,0xe6,0x5c,0x4e,
    0x56,0x9d,0xf0,0x14,0xcf,0x68,0x0c,0x39,0xd5,0xfa,0x98,0xf1,0xfd,0x0d,0x57,0xe5,
    0x1a,0xa9,0xad,0x8d,0x3d,0x60,0x09,0xb0,0x6a,0x83,0x25,0xc1,0xea,0x0c,0x16,0x81,
    0x35,0x19,0x2c,0x05,0x76,0xc4,0x60,0x55,0x60,0xad,0x06,0x4b,0x83,0x9d,0x30,0x58,
    0x06,0xec,0x94,0xc1,0xaa,0xc1,0xce,0x19,0xac,0x06,0xac,0xd3,0xeb,0x8a,0x76,0xea,
    0x53,0x8d,0x39,0x34,0x7e,0xae,0x8f,0xed,0x3e,0x39,0x1f,0x47,0x5f,0xb0,0x8f,0xa1,
    0x51,0xed,0xfc,0xae,0xfb,0x3c,0xf7,0x1a,0xaf,0x5e,0xfe,0x93,0xde,0x8e,0xbc,0x56,
    0x3d,0x37,0xc8,0x29,0x8d,0x96,0x46,0xe1,0x67,0xd0,0x92,0xc4,0xde,0x8f,0x9d,0xf2,
    0x9c,0x94,0xf4,0x2a,0xce,0xa5,0xf8,0x65,0xec,0x5a,0xb0,0xac,0xd8,0x59,0x62,0x05,
    0xbb,0x01,0x5b,0x7f,0x47,0xdd,0xbe,0x9d,0xef,0x12,0x56,0x96,0x95,0x66,0x6f,0x30,
    0x4b,0xf3,0x35,0xf1,0x7d,0x1a,0xc9,0xa7,0xf6,0x61,0xb0,0xb3,0xe4,0x6b,0x26,0x9f,
    0xf2,0x5b,0xb8,0xcb,0x98,0xfb,0x90,0x3f,0xd8,0xed,0xdc,0x2b,0xff,0x24,0x7c,0xcd,
    0x77,0x48,0x54,0x9f,0x86,0xa7,0xf6,0x99,0x5d,0x7e,0x5d,0xf4,0x2f,0xd8,0xdd,0xf8,
    0x6a,0x9c,0x1e,0xe6,0x27,0x4b,0x9d,0x3d,0xcc,0x6c,0xe4,0xeb,0xad,0x71,0xbd,0xe4,
    0x48,0x10,0x73,0xf7,0xae,0x31,0x6e,0x72,0xee,0x25,0x86,0xda,0x7d,0x60,0xcd,0x52,
    0xdb,0x00,0xbc,0x5b,0x60,0x03,0xf0,0xd4,0xce,0x83,0xb5,0x48,0xc6,0x21,0x62,0x84,
    0x3a,0x47,0xe8,0x67,0xb0,0xc7,0xa8,0x4b,0x63,0xdd,0x43,0x43,0x96,0x7e,0x8f,0xd3,
    0x8b,0x08,0xbb,0x44,0xdd,0xda,0xff,0x8b,0x32,0xaf,0x49,0xce,0x0e,0xce,0x6f,0x41,
    0xf4,0x3d,0x5c,0x61,0x56,0xa6,0x99,0x87,0x01,0x41,0x35,0xce,0x0c,0x98,0x33,0xd8,
    0x2c,0x98,0x6a,0xef,0x17,0x4c,0x7b,0x31,0x07,0x57,0xef,0xae,0x0a,0xa6,0x7d,0x7c,
    0x4a,0xaf,0x9b,0x89,0xaf,0xbc,0x32,0xf8,0x1a,0x7e,0x15,0x7c,0xcb,0xc6,0xef,0x19,
    0x7e,0xad,0xc6,0x6f,0x01,0x7c,0x05,0xbf,0x45,0x7c,0x17,0xf0,0xd3,0x39,0x78,0x8e,
    0x5f,0x3b,0x7e,0xaa,0xfb,0x05,0xf8,0x0f,0xe1,0xe8,0x6c,0xbc,0x04,0xd3,0xd9,0xf8,
    0x25,0x5f,0x60,0x19,0x6d,0x7f,0x85,0xaf,0x77,0x4b,0xb2,0x96,0xf9,0x2e,0x4b,0x46,
    0xf3,0x2b,0x72,0xea,0xef,0xb5,0x70,0xd3,0x7e,0x8f,0xf1,0x5b,0x62,0x69,0x4d,0x5b,
    0x60,0x81,0xf7,0x47,0x62,0x84,0x58,0xba,0xff,0x14,0x96,0xf2,0xbe,0xc2,0xa9,0xc2,
    0x67,0xc9,0x68,0x78,0x83,0x86,0x2e,0xa3,0x61,0x05,0x3c,0x68,0x58,0x05,0x0b,0x1a,
    0xd6,0x8d,0x86,0x55,0xff,0x6d,0x9d,0xc7,0x34,0xef,0x9a,0xd1,0xf0,0x96,0xdc,0x09,
    0xa3,0xe1,0x1d,0x78,0xd0,0xf0,0x05,0x2c,0xf0,0x54,0x43,0x88,0xb5,0x6e,0x34,0x6c,
    0xc3,0x59,0xc6,0x67,0xcd,0x68,0x78,0x8f,0x86,0x6e,0xa3,0xe1,0x03,0x78,0xd0,0xf0,
    0x11,0x2c,0x68,0xd8,0x34,0x1a,0xf4,0x6e,0x43,0xd6,0x26,0x79,0x37,0xfc,0x3b,0x8a,
    0xf3,0x7e,0x22,0xf7,0xb6,0x79,0x7b,0x5a,0x63,0xe0,0x6e,0x9a,0x1a,0xbf,0xc1,0x5b,
    0xc7,0x6f,0x83,0x7a,0x7a,0xfd,0xdc,0xc6,0x6f,0x53,0x6d,0x7d,0x87,0x83,0xbc,0xc1,
    0x61,0xa9,0x6f,0xc8,0xef,0x31,0x67,0xd0,0xcc,0xe5,0x1d,0x74,0x8d,0x98,0xb9,0x1c,
    0x05,0x0f,0xf3,0x7c,0x97,0xbc,0xa3,0xf8,0xe9,0xfb,0xbc,0x8f,0xdf,0x18,0x7e,0xfa,
    0x56,0x0b,0xe0,0xb3,0xf4,0xe1,0x01,0x58,0xe8,0xd5,0x43,0x62,0xd9,0x77,0x37,0x01,
    0x16,0xbf,0xbb,0xb4,0x7f,0xeb,0x45,0xb8,0x13,0xc4,0xb8,0x2d,0x5c,0x7d,0xf3,0x8f,
    0xd0,0x50,0xc4,0x5f,0x7b,0xf0,0x18,0xdc,0xf9,0x99,0x8b,0xeb,0x98,0x04,0xef,0x96,
    0x1e,0xe4,0xb0,0xff,0x49,0x86,0x4b,0xb2,0xfe,0x03,0xfe,0xcd,0x99,0xae,0x38,0x08,
    0x00,0x00
};

// Generated from:
//
// #version 450 core
//
// #extension GL_GOOGLE_include_directive : require
//
// #extension GL_ARB_shader_stencil_export : require
//
// layout(set = 0, binding = 1)uniform utexture2DArray stencil;
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
//     gl_FragStencilRefARB = int(texture(usampler2DArray(stencil, blitSampler), vec3(srcImageCoords * params . invSrcExtent, params . srcLayer)). x);
//
// }