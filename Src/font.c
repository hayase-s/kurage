/*
 * font.c
 *
 *  Created on: 2018/06/08
 *      Author: shun
 */

#include <stdint.h>
#include "font.h"

const uint8_t g_Font[192][5] = { { 0x00, 0x00, 0x00, 0x00, 0x00 }, // " " 0x20
		{ 0x00, 0x00, 0x4f, 0x00, 0x00 }, // !   0x21
		{ 0x00, 0x07, 0x00, 0x07, 0x00 }, // "   0x22
		{ 0x14, 0x7f, 0x14, 0x7f, 0x14 }, // #   0x23
		{ 0x24, 0x2a, 0x7f, 0x2a, 0x12 }, // $   0x24
		{ 0x23, 0x13, 0x08, 0x64, 0x62 }, // %   0x25
		{ 0x36, 0x49, 0x55, 0x22, 0x50 }, // &   0x26
		{ 0x00, 0x05, 0x03, 0x00, 0x00 }, // '   0x27
		{ 0x00, 0x1c, 0x22, 0x41, 0x00 }, // (   0x28
		{ 0x00, 0x41, 0x22, 0x1c, 0x00 }, // )   0x29
		{ 0x14, 0x08, 0x3e, 0x08, 0x14 }, // *   0x2A
		{ 0x08, 0x08, 0x3e, 0x08, 0x08 }, // +   0x2B
		{ 0x00, 0x50, 0x30, 0x00, 0x00 }, // ,   0x2C
		{ 0x08, 0x08, 0x08, 0x08, 0x08 }, // -   0x2D
		{ 0x00, 0x60, 0x60, 0x00, 0x00 }, // .   0x2E
		{ 0x20, 0x10, 0x08, 0x04, 0x02 }, // /   0x2F
		{ 0x3e, 0x51, 0x49, 0x45, 0x3e }, // 0   0x30
		{ 0x00, 0x42, 0x7f, 0x40, 0x00 }, // 1   0x31
		{ 0x42, 0x61, 0x51, 0x49, 0x46 }, // 2   0x32
		{ 0x21, 0x41, 0x45, 0x4b, 0x31 }, // 3   0x33
		{ 0x18, 0x14, 0x12, 0x7f, 0x10 }, // 4   0x34
		{ 0x27, 0x45, 0x45, 0x45, 0x39 }, // 5   0x35
		{ 0x3c, 0x4a, 0x49, 0x49, 0x30 }, // 6   0x36
		{ 0x01, 0x71, 0x09, 0x05, 0x03 }, // 7   0x37
		{ 0x36, 0x49, 0x49, 0x49, 0x36 }, // 8   0x38
		{ 0x06, 0x49, 0x49, 0x29, 0x1e }, // 9   0x39
		{ 0x00, 0x36, 0x36, 0x00, 0x00 }, // :   0x3A
		{ 0x00, 0x56, 0x36, 0x00, 0x00 }, // ;   0x3B
		{ 0x08, 0x14, 0x22, 0x41, 0x00 }, // <   0x3C
		{ 0x14, 0x14, 0x14, 0x14, 0x14 }, // =   0x3D
		{ 0x00, 0x41, 0x22, 0x14, 0x08 }, // >   0x3E
		{ 0x02, 0x01, 0x51, 0x09, 0x06 }, // ?   0x3F
		{ 0x32, 0x49, 0x79, 0x41, 0x3e }, // @   0x40
		{ 0x7e, 0x11, 0x11, 0x11, 0x7e }, // A   0x41
		{ 0x7f, 0x49, 0x49, 0x49, 0x36 }, // B   0x42
		{ 0x3e, 0x41, 0x41, 0x41, 0x22 }, // C   0x43
		{ 0x7f, 0x41, 0x41, 0x22, 0x1c }, // D   0x44
		{ 0x7f, 0x49, 0x49, 0x49, 0x41 }, // E   0x45
		{ 0x7f, 0x09, 0x09, 0x09, 0x01 }, // F   0x46
		{ 0x3e, 0x41, 0x49, 0x49, 0x7a }, // G   0x47
		{ 0x7f, 0x08, 0x08, 0x08, 0x7f }, // H   0x48
		{ 0x00, 0x41, 0x7f, 0x41, 0x00 }, // I   0x49
		{ 0x20, 0x40, 0x41, 0x3f, 0x01 }, // J   0x4A
		{ 0x7f, 0x08, 0x14, 0x22, 0x41 }, // K   0x4B
		{ 0x7f, 0x40, 0x40, 0x40, 0x40 }, // L   0x4C
		{ 0x7f, 0x02, 0x0c, 0x02, 0x7f }, // M   0x4D
		{ 0x7f, 0x04, 0x08, 0x10, 0x7f }, // N   0x4E
		{ 0x3e, 0x41, 0x41, 0x41, 0x3e }, // O   0x4F
		{ 0x7f, 0x09, 0x09, 0x09, 0x06 }, // P   0X50
		{ 0x3e, 0x41, 0x51, 0x21, 0x5e }, // Q   0X51
		{ 0x7f, 0x09, 0x19, 0x29, 0x46 }, // R   0X52
		{ 0x46, 0x49, 0x49, 0x49, 0x31 }, // S   0X53
		{ 0x01, 0x01, 0x7f, 0x01, 0x01 }, // T   0X54
		{ 0x3f, 0x40, 0x40, 0x40, 0x3f }, // U   0X55
		{ 0x1f, 0x20, 0x40, 0x20, 0x1f }, // V   0X56
		{ 0x3f, 0x40, 0x38, 0x40, 0x3f }, // W   0X57
		{ 0x63, 0x14, 0x08, 0x14, 0x63 }, // X   0X58
		{ 0x07, 0x08, 0x70, 0x08, 0x07 }, // Y   0X59
		{ 0x61, 0x51, 0x49, 0x45, 0x43 }, // Z   0X5A
		{ 0x00, 0x7f, 0x41, 0x41, 0x00 }, // [   0X5B
		{ 0x02, 0x04, 0x08, 0x10, 0x20 }, // "\" 0X5C
		{ 0x00, 0x41, 0x41, 0x7f, 0x00 }, // ]   0X5D
		{ 0x04, 0x02, 0x01, 0x02, 0x04 }, // ^   0X5E
		{ 0x40, 0x40, 0x40, 0x40, 0x40 }, // _   0X5F
		{ 0x00, 0x01, 0x02, 0x04, 0x00 }, // `   0X60
		{ 0x20, 0x54, 0x54, 0x54, 0x78 }, // a   0X61
		{ 0x7f, 0x48, 0x44, 0x44, 0x38 }, // b   0X62
		{ 0x38, 0x44, 0x44, 0x44, 0x20 }, // c   0X63
		{ 0x38, 0x44, 0x44, 0x48, 0x7f }, // d   0X64
		{ 0x38, 0x54, 0x54, 0x54, 0x18 }, // e   0X65
		{ 0x08, 0x7e, 0x09, 0x01, 0x02 }, // f   0X66
		{ 0x0c, 0x52, 0x52, 0x52, 0x3e }, // g   0X67
		{ 0x7f, 0x08, 0x04, 0x04, 0x78 }, // h   0X68
		{ 0x00, 0x44, 0x7d, 0x40, 0x00 }, // i   0X69
		{ 0x20, 0x40, 0x44, 0x3d, 0x00 }, // j   0X6A
		{ 0x7f, 0x10, 0x28, 0x44, 0x00 }, // k   0X6B
		{ 0x00, 0x41, 0x7f, 0x40, 0x00 }, // l   0X6C
		{ 0x7c, 0x04, 0x18, 0x04, 0x78 }, // m   0X6D
		{ 0x7c, 0x08, 0x04, 0x04, 0x78 }, // n   0X6E
		{ 0x38, 0x44, 0x44, 0x44, 0x38 }, // o   0X6F
		{ 0x7c, 0x14, 0x14, 0x14, 0x08 }, // p   0X70
		{ 0x08, 0x14, 0x14, 0x18, 0x7c }, // q   0X71
		{ 0x7c, 0x08, 0x04, 0x04, 0x08 }, // r   0X72
		{ 0x48, 0x54, 0x54, 0x54, 0x20 }, // s   0X73
		{ 0x04, 0x3f, 0x44, 0x40, 0x20 }, // t   0X74
		{ 0x3c, 0x40, 0x40, 0x20, 0x7c }, // u   0X75
		{ 0x1c, 0x20, 0x40, 0x20, 0x1c }, // v   0X76
		{ 0x3c, 0x40, 0x30, 0x40, 0x3c }, // w   0X77
		{ 0x44, 0x28, 0x10, 0x28, 0x44 }, // x   0X78
		{ 0x0c, 0x50, 0x50, 0x50, 0x3c }, // y   0X79
		{ 0x44, 0x64, 0x54, 0x4c, 0x44 }, // z   0X7A
		{ 0x00, 0x08, 0x36, 0x41, 0x00 }, // {   0X7B
		{ 0x00, 0x00, 0x7f, 0x00, 0x00 }, // |   0X7C
		{ 0x00, 0x41, 0x36, 0x08, 0x00 }, // }   0X7D
		{ 0x08, 0x08, 0x2a, 0x1c, 0x08 }, // ->  0X7E
		{ 0x08, 0x1c, 0x2a, 0x08, 0x08 }, // <-  0X7F
		{ 0x00, 0x00, 0x0f, 0x08, 0x08 }, //     0x80
		{ 0x08, 0x08, 0x0f, 0x00, 0x00 }, //     0x81
		{ 0x2c, 0x32, 0x02, 0x32, 0x2c }, // ohm 0x82
		{ 0x44, 0x3c, 0x04, 0x7c, 0x44 }, // pi  0x83
		{ 0x63, 0x55, 0x49, 0x41, 0x41 }, // siguma0x84
		{ 0x14, 0x14, 0x7c, 0x14, 0x12 }, // sec 0x85
		{ 0x44, 0x3c, 0x14, 0x14, 0x74 }, // man 0x86
		{ 0x7c, 0x14, 0x1c, 0x14, 0x7c }, // en  0x87
		{ 0x10, 0x10, 0x54, 0x10, 0x10 }, // waru0x88
		{ 0x7f, 0x7f, 0x7f, 0x7f, 0x7f }, //     0x89
		{ 0x0f, 0x0f, 0x0f, 0x0f, 0x0f }, //     0x8A
		{ 0x00, 0x00, 0x00, 0x00, 0x00 }, //     0x8B
		{ 0x00, 0x00, 0x00, 0x00, 0x00 }, //     0x8C
		{ 0x00, 0x00, 0x00, 0x00, 0x00 }, //     0x8D
		{ 0x00, 0x00, 0x00, 0x00, 0x00 }, //     0x8E
		{ 0x00, 0x00, 0x00, 0x00, 0x00 }, //     0x8F
		{ 0x00, 0x00, 0x00, 0x00, 0x00 }, //     0x90
		{ 0x00, 0x00, 0x00, 0x00, 0x00 }, //     0x91
		{ 0x00, 0x00, 0x00, 0x00, 0x00 }, //     0x92
		{ 0x00, 0x00, 0x00, 0x00, 0x00 }, //     0x93
		{ 0x00, 0x00, 0x00, 0x00, 0x00 }, //     0x94
		{ 0x00, 0x00, 0x00, 0x00, 0x00 }, //     0x95
		{ 0x00, 0x00, 0x00, 0x00, 0x00 }, //     0x96
		{ 0x00, 0x00, 0x00, 0x00, 0x00 }, //     0x97
		{ 0x00, 0x00, 0x00, 0x00, 0x00 }, //     0x98
		{ 0x00, 0x00, 0x00, 0x00, 0x00 }, //     0x99
		{ 0x00, 0x00, 0x00, 0x00, 0x00 }, //     0x9A
		{ 0x00, 0x00, 0x00, 0x00, 0x00 }, //     0x9B
		{ 0x00, 0x00, 0x00, 0x00, 0x00 }, //     0x9C
		{ 0x00, 0x00, 0x00, 0x00, 0x00 }, //     0x9D
		{ 0x00, 0x00, 0x00, 0x00, 0x00 }, //     0x9E
		{ 0x00, 0x00, 0x00, 0x00, 0x00 }, //     0x9F
		{ 0x00, 0x00, 0x00, 0x00, 0x00 }, //     0xA0
		{ 0x70, 0x50, 0x70, 0x00, 0x00 }, //  .  0xA1
		{ 0x00, 0x00, 0x0f, 0x01, 0x01 }, //  [  0xA2
		{ 0x40, 0x40, 0x78, 0x00, 0x00 }, //  ]  0xA3
		{ 0x10, 0x20, 0x40, 0x00, 0x00 }, //  ,  0xA4
		{ 0x00, 0x18, 0x18, 0x00, 0x00 }, //  .  0xA5
		{ 0x0a, 0x0a, 0x4a, 0x2a, 0x1e }, // wo  0xA6
		{ 0x04, 0x24, 0x34, 0x14, 0x0c }, // a   0xA7
		{ 0x20, 0x10, 0x78, 0x04, 0x00 }, // i   0xA8
		{ 0x18, 0x08, 0x4c, 0x48, 0x38 }, // u   0xA9
		{ 0x48, 0x48, 0x78, 0x48, 0x48 }, // e   0xAA
		{ 0x48, 0x28, 0x18, 0x7c, 0x08 }, // o   0xAB
		{ 0x08, 0x7c, 0x08, 0x28, 0x18 }, // ya  0xAC
		{ 0x40, 0x48, 0x48, 0x78, 0x40 }, // yu  0xAD
		{ 0x54, 0x54, 0x54, 0x7c, 0x00 }, // yo  0xAE
		{ 0x18, 0x00, 0x58, 0x40, 0x38 }, // tu  0xAF
		{ 0x08, 0x08, 0x08, 0x08, 0x08 }, //  -  0xB0
		{ 0x01, 0x41, 0x3d, 0x09, 0x07 }, //  a  0xB1
		{ 0x20, 0x10, 0x7c, 0x02, 0x01 }, //  i  0xB2
		{ 0x0e, 0x02, 0x43, 0x22, 0x1e }, //  u  0xB3
		{ 0x42, 0x42, 0x7e, 0x42, 0x42 }, //  e  0xB4
		{ 0x22, 0x12, 0x0a, 0x7f, 0x02 }, //  o  0xB5
		{ 0x42, 0x3f, 0x02, 0x42, 0x3e }, // ka  0xB6
		{ 0x0a, 0x0a, 0x7f, 0x0a, 0x0a }, // ki  0xB7
		{ 0x08, 0x46, 0x42, 0x22, 0x1e }, // ku  0xB8
		{ 0x04, 0x03, 0x42, 0x3e, 0x04 }, // ke  0xB9
		{ 0x42, 0x42, 0x42, 0x42, 0x7e }, // ko  0xBA
		{ 0x02, 0x4f, 0x22, 0x1f, 0x02 }, // sa  0xBB
		{ 0x4a, 0x4a, 0x40, 0x20, 0x1c }, // si  0xBC
		{ 0x42, 0x22, 0x12, 0x2a, 0x46 }, // su  0xBD
		{ 0x02, 0x3f, 0x42, 0x4a, 0x46 }, // se  0xBE
		{ 0x06, 0x48, 0x40, 0x20, 0x1e }, // so  0xBF
		{ 0x08, 0x46, 0x4a, 0x32, 0x1e }, // ta  0xC0
		{ 0x0a, 0x4a, 0x3e, 0x09, 0x08 }, // ti  0xC1
		{ 0x0e, 0x00, 0x4e, 0x20, 0x1e }, // tu  0xC2
		{ 0x04, 0x45, 0x3d, 0x05, 0x04 }, // te  0xC3
		{ 0x00, 0x7f, 0x08, 0x10, 0x00 }, // to  0xC4
		{ 0x44, 0x24, 0x1f, 0x04, 0x04 }, // na  0xC5
		{ 0x40, 0x42, 0x42, 0x42, 0x40 }, // ni  0xC6
		{ 0x42, 0x2a, 0x12, 0x2a, 0x06 }, // nu  0xC7
		{ 0x22, 0x12, 0x7b, 0x16, 0x22 }, // ne  0xC8
		{ 0x00, 0x40, 0x20, 0x1f, 0x00 }, // no  0xC9
		{ 0x78, 0x00, 0x02, 0x04, 0x78 }, // ha  0xCA
		{ 0x3f, 0x44, 0x44, 0x44, 0x44 }, // hi  0xCB
		{ 0x02, 0x42, 0x42, 0x22, 0x1e }, // hu  0xCC
		{ 0x04, 0x02, 0x04, 0x08, 0x30 }, // he  0xCD
		{ 0x32, 0x02, 0x7f, 0x02, 0x32 }, // ho  0xCE
		{ 0x02, 0x12, 0x22, 0x52, 0x0e }, // ma  0xCF
		{ 0x00, 0x2a, 0x2a, 0x2a, 0x40 }, // mi  0xD0
		{ 0x38, 0x24, 0x22, 0x20, 0x70 }, // mu  0xD1
		{ 0x40, 0x28, 0x10, 0x28, 0x06 }, // me  0xD2
		{ 0x0a, 0x3e, 0x4a, 0x4a, 0x4a }, // mo  0xD3
		{ 0x04, 0x7f, 0x04, 0x14, 0x0c }, // ya  0xD4
		{ 0x40, 0x42, 0x42, 0x7e, 0x40 }, // yu  0xD5
		{ 0x4a, 0x4a, 0x4a, 0x4a, 0x7e }, // yo  0xD6
		{ 0x04, 0x05, 0x45, 0x25, 0x1c }, // ra  0xD7
		{ 0x0f, 0x40, 0x20, 0x1f, 0x00 }, // ri  0xD8
		{ 0x7c, 0x00, 0x7e, 0x80, 0x30 }, // ru  0xD9
		{ 0x7e, 0x40, 0x20, 0x10, 0x08 }, // re  0xDA
		{ 0x7e, 0x42, 0x42, 0x42, 0x7e }, // ro  0xDB
		{ 0x0e, 0x02, 0x42, 0x22, 0x1e }, // wa  0xDC
		{ 0x42, 0x42, 0x40, 0x20, 0x18 }, // n   0xDD
		{ 0x02, 0x04, 0x01, 0x02, 0x00 }, // "   0xDE
		{ 0x07, 0x05, 0x07, 0x00, 0x00 } // .   0xDF

};

const uint8_t g_Cat[6][128] = { { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xFC, 0x38, 0xF0, 0xC0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 },
		{ 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
				0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x98, 0xF8, 0xF0, 0xFE, 0xFF,
				0xE3, 0x74, 0x7B, 0xFC, 0xB8, 0xF8, 0xF0, 0xE0, 0xE0, 0xC0,
				0xC0, 0xC0, 0x80, 0x80, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0,
				0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
				0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 }, { 0x0, 0x0, 0x0, 0x0, 0x0,
				0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xE0, 0xF0,
				0x5C, 0xF7, 0x3B, 0x1F, 0x3, 0x1, 0x0, 0x1, 0xC0, 0xC8, 0xFF,
				0xFF, 0xFF, 0xFF, 0xF7, 0xFF, 0xA7, 0x9F, 0x5, 0x21, 0xF5, 0xFD,
				0xFE, 0xDF, 0xFE, 0xCA, 0xE0, 0xF9, 0xFB, 0xC, 0x0, 0x0, 0x0,
				0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
				0x0 }, { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
				0x0, 0x0, 0x0, 0x3C, 0x49, 0xF1, 0x50, 0x10, 0xE0, 0xE0, 0xC0,
				0xC4, 0x82, 0x8F, 0xAF, 0xFF, 0xEE, 0xE4, 0x78, 0xF1, 0xF2,
				0xD1, 0xC1, 0xDF, 0xFE, 0x62, 0x44, 0xDB, 0xC6, 0x63, 0x1B,
				0x54, 0xFF, 0xFE, 0x7F, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
				0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 }, { 0x0, 0x0,
				0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
				0x0, 0x2, 0x5, 0xEA, 0xE7, 0x12, 0x99, 0xF6, 0x99, 0xE3, 0x8F,
				0xD7, 0xE5, 0x8B, 0xB6, 0x6A, 0xF8, 0xF7, 0xFF, 0xFF, 0xFF,
				0x1E, 0x1C, 0x1C, 0x19, 0xE8, 0xF7, 0xBE, 0xFF, 0x7F, 0x10, 0x0,
				0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
				0x0, 0x0, 0x0, 0x0 },
		{ 0x0, 0x40, 0x20, 0x0, 0x10, 0x0, 0x88, 0x8, 0x8, 0x8, 0x0, 0x8, 0x48,
				0x48, 0xF0, 0x3E, 0x5F, 0x1F, 0x23, 0x43, 0x4A, 0x4E, 0xC, 0xF,
				0x11, 0x13, 0x23, 0x43, 0x1, 0x7, 0x63, 0x3, 0xD, 0x7, 0x0, 0x1,
				0x1, 0x1, 0x41, 0xC1, 0xC0, 0xE1, 0xE1, 0xF1, 0xFB, 0xFC, 0xFC,
				0xFE, 0xFC, 0xFC, 0xC0, 0xC0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
				0x0, 0x0, 0x0, 0x0, 0x0 } };
