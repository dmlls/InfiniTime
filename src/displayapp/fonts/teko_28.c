/*******************************************************************************
 * Size: 28 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef TEKO_28
#define TEKO_28 1
#endif

#if TEKO_28

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0030 "0" */
    0x7d, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc6, 0xf8,

    /* U+0031 "1" */
    0xf3, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33,

    /* U+0032 "2" */
    0x7d, 0x8f, 0x1e, 0x3c, 0x60, 0xc1, 0x86, 0xc,
    0x38, 0x61, 0xc3, 0x6, 0x18, 0x30, 0xc1, 0xfc,

    /* U+0033 "3" */
    0x7d, 0x8f, 0x1e, 0x3c, 0x60, 0xc1, 0x83, 0x3c,
    0xc, 0x18, 0x3c, 0x78, 0xf1, 0xe3, 0xc6, 0xf8,

    /* U+0034 "4" */
    0x6, 0x6, 0x3, 0x1, 0x81, 0x80, 0xc0, 0xe0,
    0x60, 0x30, 0x31, 0x98, 0xcc, 0x6c, 0x37, 0xfc,
    0xc, 0x6, 0x3, 0x1, 0x80,

    /* U+0035 "5" */
    0xff, 0x83, 0x6, 0xc, 0x18, 0x30, 0x7e, 0x6,
    0xc, 0x18, 0x3c, 0x78, 0xf1, 0xe3, 0xc6, 0xf8,

    /* U+0036 "6" */
    0x7d, 0x8f, 0x1e, 0x3c, 0x78, 0xf0, 0x60, 0xfd,
    0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc6, 0xf8,

    /* U+0037 "7" */
    0xfe, 0xc, 0x38, 0x60, 0xc1, 0x86, 0xc, 0x18,
    0x30, 0xc1, 0x83, 0x6, 0x18, 0x30, 0x60, 0xc0,

    /* U+0038 "8" */
    0x7d, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0x7d,
    0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc6, 0xf8,

    /* U+0039 "9" */
    0x7d, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc6,
    0xfc, 0x18, 0x3c, 0x78, 0xf1, 0xe3, 0xc6, 0xf8,

    /* U+0041 "A" */
    0x1c, 0xe, 0x7, 0x82, 0xc3, 0x61, 0xb0, 0xd8,
    0x64, 0x33, 0x19, 0x88, 0xcc, 0x67, 0xf3, 0x9,
    0x86, 0xc3, 0x61, 0xe0, 0xc0,

    /* U+0042 "B" */
    0xfe, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xfe, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xfe,

    /* U+0043 "C" */
    0x7d, 0x8f, 0x1e, 0x3c, 0x78, 0x30, 0x60, 0xc1,
    0x83, 0x6, 0xc, 0x18, 0xf1, 0xe3, 0xc6, 0xf8,

    /* U+0044 "D" */
    0xfe, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xfe,

    /* U+0045 "E" */
    0xff, 0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xfd,
    0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0xfc,

    /* U+0046 "F" */
    0xff, 0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xfd,
    0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x80,

    /* U+0047 "G" */
    0x7d, 0x8f, 0x1e, 0x3c, 0x78, 0x30, 0x60, 0xc1,
    0x9f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc6, 0xf8,

    /* U+0048 "H" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3,

    /* U+0049 "I" */
    0xff, 0xff, 0xff, 0xff, 0xf0,

    /* U+004A "J" */
    0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83, 0x6,
    0xc, 0x18, 0x30, 0x78, 0xf1, 0xe3, 0xc6, 0xf8,

    /* U+004B "K" */
    0xc3, 0xc6, 0xc6, 0xce, 0xcc, 0xcc, 0xd8, 0xd8,
    0xf0, 0xf0, 0xd8, 0xd8, 0xcc, 0xcc, 0xcc, 0xc6,
    0xc6, 0xc3,

    /* U+004C "L" */
    0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xc,
    0x30, 0xc3, 0xc, 0x30, 0xc3, 0xf0,

    /* U+004D "M" */
    0xe1, 0xf8, 0x7e, 0x1f, 0x87, 0xe1, 0xfc, 0xff,
    0x3f, 0x4b, 0xd2, 0xf7, 0xbd, 0xef, 0x33, 0xcc,
    0xf3, 0x3c, 0xf, 0x3, 0xc0, 0xf0, 0x30,

    /* U+004E "N" */
    0xe3, 0xe3, 0xe3, 0xe3, 0xf3, 0xf3, 0xd3, 0xd3,
    0xdb, 0xdb, 0xcb, 0xcb, 0xcf, 0xcf, 0xc7, 0xc7,
    0xc7, 0xc3,

    /* U+004F "O" */
    0x7d, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc6, 0xf8,

    /* U+0050 "P" */
    0xfd, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0xfb, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x80,

    /* U+0051 "Q" */
    0x7d, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc6, 0xf8,
    0x30, 0x60, 0x60,

    /* U+0052 "R" */
    0xfc, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6,
    0xc6, 0xfc, 0xc8, 0xcc, 0xcc, 0xcc, 0xc6, 0xc6,
    0xc6, 0xc3,

    /* U+0053 "S" */
    0x7d, 0x8f, 0x1e, 0x3c, 0x78, 0x30, 0x60, 0x7c,
    0xc, 0x18, 0x30, 0x78, 0xf1, 0xe3, 0xc6, 0xf8,

    /* U+0054 "T" */
    0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18,

    /* U+0055 "U" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc6, 0xf8,

    /* U+0056 "V" */
    0xc1, 0xe0, 0xd0, 0xcc, 0x66, 0x33, 0x19, 0x8c,
    0xc6, 0x62, 0x13, 0xd, 0x86, 0xc3, 0x61, 0xb0,
    0xd8, 0x28, 0x1c, 0xe, 0x0,

    /* U+0057 "W" */
    0xc3, 0x87, 0x87, 0xd, 0x8e, 0x1b, 0x1c, 0x36,
    0x38, 0x4c, 0x59, 0x98, 0xb3, 0x31, 0x66, 0x66,
    0xcc, 0x4d, 0x98, 0xd9, 0x31, 0xb2, 0x43, 0x44,
    0x86, 0x8f, 0xd, 0x1e, 0x1e, 0x3c, 0x1c, 0x78,
    0x38, 0x70,

    /* U+0058 "X" */
    0x61, 0xb1, 0x98, 0xc6, 0x63, 0x61, 0xb0, 0x78,
    0x38, 0xc, 0xe, 0x7, 0x2, 0xc3, 0x61, 0x99,
    0x8c, 0xc6, 0x61, 0xe0, 0xc0,

    /* U+0059 "Y" */
    0xc3, 0xc3, 0xc3, 0x42, 0x66, 0x66, 0x66, 0x24,
    0x3c, 0x3c, 0x3c, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18,

    /* U+005A "Z" */
    0xfe, 0xc, 0x18, 0x60, 0xc1, 0x6, 0xc, 0x10,
    0x60, 0xc1, 0x6, 0xc, 0x10, 0x60, 0xc1, 0xfc,

    /* U+0061 "a" */
    0x7f, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3c, 0x6f, 0xc0,

    /* U+0062 "b" */
    0xc1, 0x83, 0x6, 0xc, 0x1f, 0xb1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7, 0x8f,
    0xf0,

    /* U+0063 "c" */
    0x7d, 0x8f, 0x1e, 0x3c, 0x18, 0x30, 0x60, 0xc1,
    0x83, 0x1e, 0x3c, 0x6f, 0x80,

    /* U+0064 "d" */
    0x6, 0xc, 0x18, 0x30, 0x6f, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7, 0x8d,
    0xf8,

    /* U+0065 "e" */
    0x7d, 0x8f, 0x1e, 0x3c, 0x78, 0xff, 0xe0, 0xc1,
    0x83, 0x1e, 0x3c, 0x6f, 0x80,

    /* U+0066 "f" */
    0x3b, 0x18, 0xc6, 0x7d, 0x8c, 0x63, 0x18, 0xc6,
    0x31, 0x8c, 0x63, 0x18,

    /* U+0067 "g" */
    0x7f, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3c, 0x6f, 0xc1, 0x83, 0x7, 0xf8,

    /* U+0068 "h" */
    0xc1, 0x83, 0x6, 0xc, 0x1f, 0xb1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7, 0x8f,
    0x18,

    /* U+0069 "i" */
    0xc0, 0x3f, 0xff, 0xff, 0xfc,

    /* U+006A "j" */
    0x60, 0x0, 0xdb, 0x6d, 0xb6, 0xdb, 0x6d, 0xb6,
    0xf0,

    /* U+006B "k" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc7, 0xc6, 0xc6,
    0xcc, 0xcc, 0xd8, 0xd8, 0xd8, 0xd8, 0xcc, 0xcc,
    0xc6, 0xc6, 0xc7,

    /* U+006C "l" */
    0xff, 0xff, 0xff, 0xff, 0xfc,

    /* U+006D "m" */
    0xff, 0xec, 0x63, 0xc6, 0x3c, 0x63, 0xc6, 0x3c,
    0x63, 0xc6, 0x3c, 0x63, 0xc6, 0x3c, 0x63, 0xc6,
    0x3c, 0x63, 0xc6, 0x3c, 0x63,

    /* U+006E "n" */
    0xfd, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3c, 0x78, 0xc0,

    /* U+006F "o" */
    0x7d, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3c, 0x6f, 0x80,

    /* U+0070 "p" */
    0xfd, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3c, 0x7f, 0xb0, 0x60, 0xc1, 0x80,

    /* U+0071 "q" */
    0x7f, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3c, 0x6f, 0xc1, 0x83, 0x6, 0xc,

    /* U+0072 "r" */
    0xff, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c,
    0x60,

    /* U+0073 "s" */
    0x7b, 0x3c, 0xf3, 0xc3, 0xc, 0x1f, 0xc, 0x30,
    0xf3, 0xcd, 0xe0,

    /* U+0074 "t" */
    0x63, 0x19, 0xf6, 0x31, 0x8c, 0x63, 0x18, 0xc6,
    0x31, 0x8c, 0x38,

    /* U+0075 "u" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3c, 0x6f, 0xc0,

    /* U+0076 "v" */
    0xc3, 0xc6, 0x46, 0x66, 0x66, 0x66, 0x66, 0x64,
    0x6c, 0x2c, 0x3c, 0x3c, 0x3c, 0x3c,

    /* U+0077 "w" */
    0xc3, 0xf, 0xe, 0x34, 0x78, 0xd9, 0xe2, 0x67,
    0x99, 0x9e, 0x66, 0x69, 0x99, 0x26, 0x24, 0xd8,
    0xf3, 0x43, 0xcf, 0xf, 0x3c, 0x3c, 0xf0, 0xf1,
    0xc0,

    /* U+0078 "x" */
    0x63, 0x31, 0x8d, 0x86, 0xc3, 0x40, 0xe0, 0x60,
    0x38, 0x1c, 0x1b, 0xd, 0x8c, 0xc6, 0x36, 0x18,

    /* U+0079 "y" */
    0xc3, 0xc3, 0xc2, 0xc6, 0x66, 0x66, 0x66, 0x66,
    0x64, 0x2c, 0x3c, 0x3c, 0x3c, 0x3c, 0x8, 0x18,
    0x18, 0x70,

    /* U+007A "z" */
    0xfc, 0x30, 0x86, 0x18, 0x43, 0xc, 0x21, 0x84,
    0x10, 0xc3, 0xf0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 162, .box_w = 7, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 16, .adv_w = 95, .box_w = 4, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 25, .adv_w = 130, .box_w = 7, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 41, .adv_w = 144, .box_w = 7, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 57, .adv_w = 146, .box_w = 9, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 78, .adv_w = 144, .box_w = 7, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 94, .adv_w = 158, .box_w = 7, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 110, .adv_w = 115, .box_w = 7, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 126, .adv_w = 161, .box_w = 7, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 142, .adv_w = 155, .box_w = 7, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 158, .adv_w = 154, .box_w = 9, .box_h = 18, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 179, .adv_w = 171, .box_w = 8, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 197, .adv_w = 155, .box_w = 7, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 213, .adv_w = 171, .box_w = 8, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 231, .adv_w = 141, .box_w = 7, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 247, .adv_w = 136, .box_w = 7, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 263, .adv_w = 157, .box_w = 7, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 279, .adv_w = 171, .box_w = 8, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 297, .adv_w = 89, .box_w = 2, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 302, .adv_w = 135, .box_w = 7, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 318, .adv_w = 155, .box_w = 8, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 336, .adv_w = 121, .box_w = 6, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 350, .adv_w = 213, .box_w = 10, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 373, .adv_w = 169, .box_w = 8, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 391, .adv_w = 161, .box_w = 7, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 407, .adv_w = 155, .box_w = 7, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 423, .adv_w = 161, .box_w = 7, .box_h = 21, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 442, .adv_w = 163, .box_w = 8, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 460, .adv_w = 146, .box_w = 7, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 476, .adv_w = 125, .box_w = 8, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 494, .adv_w = 163, .box_w = 7, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 510, .adv_w = 143, .box_w = 9, .box_h = 18, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 531, .adv_w = 246, .box_w = 15, .box_h = 18, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 565, .adv_w = 150, .box_w = 9, .box_h = 18, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 586, .adv_w = 143, .box_w = 8, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 604, .adv_w = 122, .box_w = 7, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 620, .adv_w = 147, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 633, .adv_w = 147, .box_w = 7, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 650, .adv_w = 146, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 663, .adv_w = 147, .box_w = 7, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 680, .adv_w = 148, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 693, .adv_w = 88, .box_w = 5, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 705, .adv_w = 147, .box_w = 7, .box_h = 18, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 721, .adv_w = 149, .box_w = 7, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 738, .adv_w = 71, .box_w = 2, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 743, .adv_w = 71, .box_w = 3, .box_h = 23, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 752, .adv_w = 146, .box_w = 8, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 771, .adv_w = 71, .box_w = 2, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 776, .adv_w = 225, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 797, .adv_w = 149, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 810, .adv_w = 152, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 823, .adv_w = 147, .box_w = 7, .box_h = 18, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 839, .adv_w = 147, .box_w = 7, .box_h = 18, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 855, .adv_w = 95, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 864, .adv_w = 133, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 875, .adv_w = 88, .box_w = 5, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 886, .adv_w = 149, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 899, .adv_w = 125, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 913, .adv_w = 227, .box_w = 14, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 938, .adv_w = 141, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 954, .adv_w = 138, .box_w = 8, .box_h = 18, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 972, .adv_w = 119, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 48, .range_length = 10, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 65, .range_length = 26, .glyph_id_start = 11,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 97, .range_length = 26, .glyph_id_start = 37,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 3,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t teko_28 = {
#else
lv_font_t teko_28 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 23,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if TEKO_28*/
