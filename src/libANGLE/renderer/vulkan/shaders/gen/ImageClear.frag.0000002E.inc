// GENERATED FILE - DO NOT EDIT.
// Generated by gen_vk_internal_shaders.py.
//
// Copyright 2018 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// shaders/gen/ImageClear.frag.0000002E.inc:
//   Pre-generated shader for the ANGLE Vulkan back-end.

#pragma once
constexpr uint8_t kImageClear_frag_0000002E[] = {
    0x1f,0x8b,0x08,0x00,0x00,0x00,0x00,0x00,0x02,0xff,0x35,0x50,0xbb,0x0a,0xc2,0x40,
    0x10,0xdc,0xe4,0xcc,0x5b,0xcd,0x69,0x50,0xbb,0x10,0x49,0x29,0x04,0x0b,0x15,0x41,
    0x14,0xac,0xb4,0x48,0xe7,0x17,0x08,0x36,0x16,0xda,0xe8,0xc7,0xdb,0x08,0xce,0x5e,
    0xc6,0x83,0xdd,0xc9,0xce,0xed,0xcc,0xee,0xc5,0xf8,0x75,0x24,0xe2,0x49,0x2a,0xb1,
    0x14,0xd2,0x9d,0x91,0xf8,0x60,0x44,0x32,0x09,0x1d,0x9e,0xda,0x4b,0xdb,0xbc,0xde,
    0xb7,0x66,0xb5,0x5e,0xea,0xfd,0x50,0x8c,0xeb,0xd3,0xbb,0x1c,0x3d,0x3d,0xa0,0xc6,
    0xe3,0x7a,0x7f,0x2a,0x9f,0x20,0x2c,0x7a,0x94,0x8b,0x54,0x8f,0x2f,0xe5,0x4a,0xd6,
    0x67,0x09,0xe0,0xdd,0x9d,0x9a,0xf8,0xe7,0x3c,0x72,0xd6,0xe9,0x8c,0xe3,0x7c,0x44,
    0x81,0xac,0x38,0x07,0x67,0xc8,0x4d,0xe0,0x1b,0x02,0x2b,0x7a,0xcc,0x50,0xab,0x7f,
    0xc8,0x7d,0x2a,0xe4,0x18,0x68,0x38,0x77,0xc7,0x3a,0x21,0x37,0x45,0x4e,0xa9,0x2f,
    0x71,0x97,0xb1,0x2f,0xa5,0xb6,0xcf,0xde,0x8c,0x5a,0xad,0x07,0xe4,0x74,0xf6,0x90,
    0x5a,0xdd,0x79,0xc1,0x3a,0xe7,0x2e,0xaa,0xb7,0xec,0x55,0xcf,0x0d,0xde,0xe7,0x73,
    0x2f,0xe1,0xfc,0x0f,0x98,0x00,0x78,0x44,0xb6,0xee,0xbf,0x77,0xfe,0xea,0xb1,0xe7,
    0x5b,0xc6,0xe4,0x0f,0x50,0x24,0xac,0xbf,0x98,0xb8,0x45,0xfc,0x00,0xe1,0xb8,0x2a,
    0x45,0xbc,0x01,0x00,0x00
};

// Generated from:
//
// #version 450 core
//
// layout(push_constant)uniform PushConstants {
//        uvec4 clearColor;
//     float clearDepth;
// } params;
//
// layout(location = 7)out uvec4 colorOut;
//
// void main()
// {
//     colorOut = params . clearColor;
//
// }