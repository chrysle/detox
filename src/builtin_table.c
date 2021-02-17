/**
 * This file is part of the Detox package.
 *
 * Copyright (c) Doug Harple <detox.dharple@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 */

#include <stdio.h>
#include "table.h"
#include "builtin_table.h"

/**
 * Generated from safe.tbl.sample
 */

static struct translation_table_row builtin_safe_rows[55] = {
    { .key  = 0x0001, .data = "_" },
    { .key  = 0x0002, .data = "_" },
    { .key  = 0x0003, .data = "_" },
    { .key  = 0x0004, .data = "_" },
    { .key  = 0x0005, .data = "_" },
    { .key  = 0x0006, .data = "_" },
    { .key  = 0x0007, .data = "_" },
    { .key  = 0x0008, .data = "_" },
    { .key  = 0x0009, .data = "_" },
    { .key  = 0x000a, .data = "_" },
    { .key  = 0x000b, .data = "_" },
    { .key  = 0x000c, .data = "_" },
    { .key  = 0x000d, .data = "_" },
    { .key  = 0x000e, .data = "_" },
    { .key  = 0x000f, .data = "_" },
    { .key  = 0x0010, .data = "_" },
    { .key  = 0x0011, .data = "_" },
    { .key  = 0x0012, .data = "_" },
    { .key  = 0x0013, .data = "_" },
    { .key  = 0x0014, .data = "_" },
    { .key  = 0x0015, .data = "_" },
    { .key  = 0x0016, .data = "_" },
    { .key  = 0x0017, .data = "_" },
    { .key  = 0x0018, .data = "_" },
    { .key  = 0x0019, .data = "_" },
    { .key  = 0x001a, .data = "_" },
    { .key  = 0x001b, .data = "_" },
    { .key  = 0x001c, .data = "_" },
    { .key  = 0x001d, .data = "_" },
    { .key  = 0x001e, .data = "_" },
    { .key  = 0x001f, .data = "_" },
    { .key  = 0x0020, .data = "_" },
    { .key  = 0x0021, .data = "_" },
    { .key  = 0x0022, .data = "_" },
    { .key  = 0x0024, .data = "_" },
    { .key  = 0x0026, .data = "_and_" },
    { .key  = 0x0027, .data = "_" },
    { .key  = 0x0028, .data = "-" },
    { .key  = 0x0029, .data = "-" },
    { .key  = 0x002a, .data = "_" },
    { .key  = 0x002f, .data = "_" },
    { .key  = 0x003a, .data = "_" },
    { .key  = 0x003b, .data = "_" },
    { .key  = 0x003c, .data = "_" },
    { .key  = 0x003e, .data = "_" },
    { .key  = 0x003f, .data = "_" },
    { .key  = 0x0040, .data = "_" },
    { .key  = 0x005b, .data = "-" },
    { .key  = 0x005c, .data = "_" },
    { .key  = 0x005d, .data = "-" },
    { .key  = 0x0060, .data = "_" },
    { .key  = 0x007b, .data = "-" },
    { .key  = 0x007c, .data = "_" },
    { .key  = 0x007d, .data = "-" },
    { .key  = 0x007f, .data = "_" },
};

static struct translation_table builtin_safe_table = {
    .length              = 55,
    .used                = 55,
    .max_data_length     = 5,
    .hits                = 0,
    .misses              = 0,
    .seeks               = 0,
    .overwrites          = 0,
    .use_hash            = 0,
    .builtin             = 1,
    .rows                = builtin_safe_rows,
    .default_translation = NULL,
};

struct translation_table *load_builtin_safe_table(void)
{
    return table_resize(&builtin_safe_table, 256, 1);
}

/**
 * Generated from iso8859_1.tbl.sample
 */

static struct translation_table_row builtin_iso8859_1_rows[88] = {
    { .key  = 0x00a0, .data = " " },
    { .key  = 0x00a1, .data = "!" },
    { .key  = 0x00a2, .data = "_cent_" },
    { .key  = 0x00a3, .data = "_pound_" },
    { .key  = 0x00a4, .data = "$" },
    { .key  = 0x00a5, .data = "_yen_" },
    { .key  = 0x00a7, .data = "_ss_" },
    { .key  = 0x00a8, .data = " " },
    { .key  = 0x00a9, .data = "_copy_" },
    { .key  = 0x00aa, .data = "_a_" },
    { .key  = 0x00ab, .data = "\"" },
    { .key  = 0x00ad, .data = "-" },
    { .key  = 0x00ae, .data = "_reg_" },
    { .key  = 0x00b0, .data = "_deg_" },
    { .key  = 0x00b2, .data = "^2" },
    { .key  = 0x00b3, .data = "^3" },
    { .key  = 0x00b4, .data = "'" },
    { .key  = 0x00b5, .data = "u" },
    { .key  = 0x00b6, .data = "_pp_" },
    { .key  = 0x00b7, .data = "*" },
    { .key  = 0x00b8, .data = " " },
    { .key  = 0x00b9, .data = "^1" },
    { .key  = 0x00ba, .data = "_o_" },
    { .key  = 0x00bb, .data = "\"" },
    { .key  = 0x00bf, .data = "?" },
    { .key  = 0x00c0, .data = "A" },
    { .key  = 0x00c1, .data = "A" },
    { .key  = 0x00c2, .data = "A" },
    { .key  = 0x00c3, .data = "A" },
    { .key  = 0x00c4, .data = "A" },
    { .key  = 0x00c5, .data = "A" },
    { .key  = 0x00c6, .data = "AE" },
    { .key  = 0x00c7, .data = "C" },
    { .key  = 0x00c8, .data = "E" },
    { .key  = 0x00c9, .data = "E" },
    { .key  = 0x00ca, .data = "E" },
    { .key  = 0x00cb, .data = "E" },
    { .key  = 0x00cc, .data = "I" },
    { .key  = 0x00cd, .data = "I" },
    { .key  = 0x00ce, .data = "I" },
    { .key  = 0x00cf, .data = "I" },
    { .key  = 0x00d0, .data = "TH" },
    { .key  = 0x00d1, .data = "N" },
    { .key  = 0x00d2, .data = "O" },
    { .key  = 0x00d3, .data = "O" },
    { .key  = 0x00d4, .data = "O" },
    { .key  = 0x00d5, .data = "O" },
    { .key  = 0x00d6, .data = "O" },
    { .key  = 0x00d7, .data = "x" },
    { .key  = 0x00d8, .data = "O" },
    { .key  = 0x00d9, .data = "U" },
    { .key  = 0x00da, .data = "U" },
    { .key  = 0x00db, .data = "U" },
    { .key  = 0x00dc, .data = "U" },
    { .key  = 0x00dd, .data = "Y" },
    { .key  = 0x00de, .data = "TH" },
    { .key  = 0x00df, .data = "ss" },
    { .key  = 0x00e0, .data = "a" },
    { .key  = 0x00e1, .data = "a" },
    { .key  = 0x00e2, .data = "a" },
    { .key  = 0x00e3, .data = "a" },
    { .key  = 0x00e4, .data = "a" },
    { .key  = 0x00e5, .data = "a" },
    { .key  = 0x00e6, .data = "ae" },
    { .key  = 0x00e7, .data = "c" },
    { .key  = 0x00e8, .data = "e" },
    { .key  = 0x00e9, .data = "e" },
    { .key  = 0x00ea, .data = "e" },
    { .key  = 0x00eb, .data = "e" },
    { .key  = 0x00ec, .data = "i" },
    { .key  = 0x00ed, .data = "i" },
    { .key  = 0x00ee, .data = "i" },
    { .key  = 0x00ef, .data = "i" },
    { .key  = 0x00f0, .data = "th" },
    { .key  = 0x00f1, .data = "n" },
    { .key  = 0x00f2, .data = "o" },
    { .key  = 0x00f3, .data = "o" },
    { .key  = 0x00f4, .data = "o" },
    { .key  = 0x00f5, .data = "o" },
    { .key  = 0x00f6, .data = "o" },
    { .key  = 0x00f8, .data = "o" },
    { .key  = 0x00f9, .data = "u" },
    { .key  = 0x00fa, .data = "u" },
    { .key  = 0x00fb, .data = "u" },
    { .key  = 0x00fc, .data = "u" },
    { .key  = 0x00fd, .data = "y" },
    { .key  = 0x00fe, .data = "th" },
    { .key  = 0x00ff, .data = "y" },
};

static struct translation_table builtin_iso8859_1_table = {
    .length              = 88,
    .used                = 88,
    .max_data_length     = 7,
    .hits                = 0,
    .misses              = 0,
    .seeks               = 0,
    .overwrites          = 0,
    .use_hash            = 0,
    .builtin             = 1,
    .rows                = builtin_iso8859_1_rows,
    .default_translation = "_",
};

struct translation_table *load_builtin_iso8859_1_table(void)
{
    return table_resize(&builtin_iso8859_1_table, 256, 1);
}

/**
 * Generated from unicode.tbl.sample
 */

static struct translation_table_row builtin_unicode_rows[594] = {
    { .key  = 0x0020, .data = " " },
    { .key  = 0x0021, .data = "!" },
    { .key  = 0x0022, .data = "\"" },
    { .key  = 0x0023, .data = "#" },
    { .key  = 0x0024, .data = "$" },
    { .key  = 0x0025, .data = "%" },
    { .key  = 0x0026, .data = "&" },
    { .key  = 0x0027, .data = "'" },
    { .key  = 0x0028, .data = "(" },
    { .key  = 0x0029, .data = ")" },
    { .key  = 0x002a, .data = "*" },
    { .key  = 0x002b, .data = "+" },
    { .key  = 0x002c, .data = "," },
    { .key  = 0x002d, .data = "-" },
    { .key  = 0x002e, .data = "." },
    { .key  = 0x002f, .data = "/" },
    { .key  = 0x0030, .data = "0" },
    { .key  = 0x0031, .data = "1" },
    { .key  = 0x0032, .data = "2" },
    { .key  = 0x0033, .data = "3" },
    { .key  = 0x0034, .data = "4" },
    { .key  = 0x0035, .data = "5" },
    { .key  = 0x0036, .data = "6" },
    { .key  = 0x0037, .data = "7" },
    { .key  = 0x0038, .data = "8" },
    { .key  = 0x0039, .data = "9" },
    { .key  = 0x003a, .data = ":" },
    { .key  = 0x003b, .data = ";" },
    { .key  = 0x003c, .data = "<" },
    { .key  = 0x003d, .data = "=" },
    { .key  = 0x003e, .data = ">" },
    { .key  = 0x003f, .data = "?" },
    { .key  = 0x0040, .data = "@" },
    { .key  = 0x0041, .data = "A" },
    { .key  = 0x0042, .data = "B" },
    { .key  = 0x0043, .data = "C" },
    { .key  = 0x0044, .data = "D" },
    { .key  = 0x0045, .data = "E" },
    { .key  = 0x0046, .data = "F" },
    { .key  = 0x0047, .data = "G" },
    { .key  = 0x0048, .data = "H" },
    { .key  = 0x0049, .data = "I" },
    { .key  = 0x004a, .data = "J" },
    { .key  = 0x004b, .data = "K" },
    { .key  = 0x004c, .data = "L" },
    { .key  = 0x004d, .data = "M" },
    { .key  = 0x004e, .data = "N" },
    { .key  = 0x004f, .data = "O" },
    { .key  = 0x0050, .data = "P" },
    { .key  = 0x0051, .data = "Q" },
    { .key  = 0x0052, .data = "R" },
    { .key  = 0x0053, .data = "S" },
    { .key  = 0x0054, .data = "T" },
    { .key  = 0x0055, .data = "U" },
    { .key  = 0x0056, .data = "V" },
    { .key  = 0x0057, .data = "W" },
    { .key  = 0x0058, .data = "X" },
    { .key  = 0x0059, .data = "Y" },
    { .key  = 0x005a, .data = "Z" },
    { .key  = 0x005b, .data = "[" },
    { .key  = 0x005c, .data = "\\" },
    { .key  = 0x005d, .data = "]" },
    { .key  = 0x005e, .data = "^" },
    { .key  = 0x005f, .data = "_" },
    { .key  = 0x0060, .data = "`" },
    { .key  = 0x0061, .data = "a" },
    { .key  = 0x0062, .data = "b" },
    { .key  = 0x0063, .data = "c" },
    { .key  = 0x0064, .data = "d" },
    { .key  = 0x0065, .data = "e" },
    { .key  = 0x0066, .data = "f" },
    { .key  = 0x0067, .data = "g" },
    { .key  = 0x0068, .data = "h" },
    { .key  = 0x0069, .data = "i" },
    { .key  = 0x006a, .data = "j" },
    { .key  = 0x006b, .data = "k" },
    { .key  = 0x006c, .data = "l" },
    { .key  = 0x006d, .data = "m" },
    { .key  = 0x006e, .data = "n" },
    { .key  = 0x006f, .data = "o" },
    { .key  = 0x0070, .data = "p" },
    { .key  = 0x0071, .data = "q" },
    { .key  = 0x0072, .data = "r" },
    { .key  = 0x0073, .data = "s" },
    { .key  = 0x0074, .data = "t" },
    { .key  = 0x0075, .data = "u" },
    { .key  = 0x0076, .data = "v" },
    { .key  = 0x0077, .data = "w" },
    { .key  = 0x0078, .data = "x" },
    { .key  = 0x0079, .data = "y" },
    { .key  = 0x007a, .data = "z" },
    { .key  = 0x007b, .data = "{" },
    { .key  = 0x007c, .data = "|" },
    { .key  = 0x007d, .data = "}" },
    { .key  = 0x007e, .data = "~" },
    { .key  = 0x00a0, .data = " " },
    { .key  = 0x00a1, .data = "!" },
    { .key  = 0x00a2, .data = "_cent_" },
    { .key  = 0x00a3, .data = "_pound_" },
    { .key  = 0x00a4, .data = "$" },
    { .key  = 0x00a5, .data = "_yen_" },
    { .key  = 0x00a7, .data = "_ss_" },
    { .key  = 0x00a8, .data = " " },
    { .key  = 0x00a9, .data = "_copy_" },
    { .key  = 0x00aa, .data = "_a_" },
    { .key  = 0x00ab, .data = "\"" },
    { .key  = 0x00ad, .data = "-" },
    { .key  = 0x00ae, .data = "_reg_" },
    { .key  = 0x00b0, .data = "_deg_" },
    { .key  = 0x00b2, .data = "^2" },
    { .key  = 0x00b3, .data = "^3" },
    { .key  = 0x00b4, .data = "'" },
    { .key  = 0x00b5, .data = "u" },
    { .key  = 0x00b6, .data = "_pp_" },
    { .key  = 0x00b7, .data = "*" },
    { .key  = 0x00b8, .data = " " },
    { .key  = 0x00b9, .data = "^1" },
    { .key  = 0x00ba, .data = "_o_" },
    { .key  = 0x00bb, .data = "\"" },
    { .key  = 0x00bf, .data = "?" },
    { .key  = 0x00c0, .data = "A" },
    { .key  = 0x00c1, .data = "A" },
    { .key  = 0x00c2, .data = "A" },
    { .key  = 0x00c3, .data = "A" },
    { .key  = 0x00c4, .data = "A" },
    { .key  = 0x00c5, .data = "A" },
    { .key  = 0x00c6, .data = "AE" },
    { .key  = 0x00c7, .data = "C" },
    { .key  = 0x00c8, .data = "E" },
    { .key  = 0x00c9, .data = "E" },
    { .key  = 0x00ca, .data = "E" },
    { .key  = 0x00cb, .data = "E" },
    { .key  = 0x00cc, .data = "I" },
    { .key  = 0x00cd, .data = "I" },
    { .key  = 0x00ce, .data = "I" },
    { .key  = 0x00cf, .data = "I" },
    { .key  = 0x00d0, .data = "TH" },
    { .key  = 0x00d1, .data = "N" },
    { .key  = 0x00d2, .data = "O" },
    { .key  = 0x00d3, .data = "O" },
    { .key  = 0x00d4, .data = "O" },
    { .key  = 0x00d5, .data = "O" },
    { .key  = 0x00d6, .data = "O" },
    { .key  = 0x00d7, .data = "x" },
    { .key  = 0x00d8, .data = "O" },
    { .key  = 0x00d9, .data = "U" },
    { .key  = 0x00da, .data = "U" },
    { .key  = 0x00db, .data = "U" },
    { .key  = 0x00dc, .data = "U" },
    { .key  = 0x00dd, .data = "Y" },
    { .key  = 0x00de, .data = "TH" },
    { .key  = 0x00df, .data = "ss" },
    { .key  = 0x00e0, .data = "a" },
    { .key  = 0x00e1, .data = "a" },
    { .key  = 0x00e2, .data = "a" },
    { .key  = 0x00e3, .data = "a" },
    { .key  = 0x00e4, .data = "a" },
    { .key  = 0x00e5, .data = "a" },
    { .key  = 0x00e6, .data = "ae" },
    { .key  = 0x00e7, .data = "c" },
    { .key  = 0x00e8, .data = "e" },
    { .key  = 0x00e9, .data = "e" },
    { .key  = 0x00ea, .data = "e" },
    { .key  = 0x00eb, .data = "e" },
    { .key  = 0x00ec, .data = "i" },
    { .key  = 0x00ed, .data = "i" },
    { .key  = 0x00ee, .data = "i" },
    { .key  = 0x00ef, .data = "i" },
    { .key  = 0x00f0, .data = "th" },
    { .key  = 0x00f1, .data = "n" },
    { .key  = 0x00f2, .data = "o" },
    { .key  = 0x00f3, .data = "o" },
    { .key  = 0x00f4, .data = "o" },
    { .key  = 0x00f5, .data = "o" },
    { .key  = 0x00f6, .data = "o" },
    { .key  = 0x00f8, .data = "o" },
    { .key  = 0x00f9, .data = "u" },
    { .key  = 0x00fa, .data = "u" },
    { .key  = 0x00fb, .data = "u" },
    { .key  = 0x00fc, .data = "u" },
    { .key  = 0x00fd, .data = "y" },
    { .key  = 0x00fe, .data = "th" },
    { .key  = 0x00ff, .data = "y" },
    { .key  = 0x0100, .data = "A" },
    { .key  = 0x0101, .data = "a" },
    { .key  = 0x0102, .data = "A" },
    { .key  = 0x0103, .data = "a" },
    { .key  = 0x0104, .data = "A" },
    { .key  = 0x0105, .data = "a" },
    { .key  = 0x0106, .data = "C" },
    { .key  = 0x0107, .data = "c" },
    { .key  = 0x0108, .data = "C" },
    { .key  = 0x0109, .data = "c" },
    { .key  = 0x010a, .data = "C" },
    { .key  = 0x010b, .data = "c" },
    { .key  = 0x010c, .data = "C" },
    { .key  = 0x010d, .data = "c" },
    { .key  = 0x010e, .data = "D" },
    { .key  = 0x010f, .data = "d" },
    { .key  = 0x0110, .data = "D" },
    { .key  = 0x0111, .data = "d" },
    { .key  = 0x0112, .data = "E" },
    { .key  = 0x0113, .data = "e" },
    { .key  = 0x0114, .data = "E" },
    { .key  = 0x0115, .data = "e" },
    { .key  = 0x0116, .data = "E" },
    { .key  = 0x0117, .data = "e" },
    { .key  = 0x0118, .data = "E" },
    { .key  = 0x0119, .data = "e" },
    { .key  = 0x011a, .data = "E" },
    { .key  = 0x011b, .data = "e" },
    { .key  = 0x011c, .data = "G" },
    { .key  = 0x011d, .data = "g" },
    { .key  = 0x011e, .data = "G" },
    { .key  = 0x011f, .data = "g" },
    { .key  = 0x0120, .data = "G" },
    { .key  = 0x0121, .data = "g" },
    { .key  = 0x0122, .data = "G" },
    { .key  = 0x0123, .data = "g" },
    { .key  = 0x0124, .data = "H" },
    { .key  = 0x0125, .data = "h" },
    { .key  = 0x0126, .data = "H" },
    { .key  = 0x0127, .data = "h" },
    { .key  = 0x0128, .data = "I" },
    { .key  = 0x0129, .data = "i" },
    { .key  = 0x012a, .data = "I" },
    { .key  = 0x012b, .data = "i" },
    { .key  = 0x012c, .data = "I" },
    { .key  = 0x012d, .data = "i" },
    { .key  = 0x012e, .data = "I" },
    { .key  = 0x012f, .data = "i" },
    { .key  = 0x0130, .data = "I" },
    { .key  = 0x0131, .data = "i" },
    { .key  = 0x0132, .data = "IJ" },
    { .key  = 0x0133, .data = "ij" },
    { .key  = 0x0134, .data = "J" },
    { .key  = 0x0135, .data = "j" },
    { .key  = 0x0136, .data = "K" },
    { .key  = 0x0137, .data = "k" },
    { .key  = 0x0138, .data = "q" },
    { .key  = 0x0139, .data = "L" },
    { .key  = 0x013a, .data = "l" },
    { .key  = 0x013b, .data = "L" },
    { .key  = 0x013c, .data = "l" },
    { .key  = 0x013d, .data = "L" },
    { .key  = 0x013e, .data = "l" },
    { .key  = 0x013f, .data = "L" },
    { .key  = 0x0140, .data = "l" },
    { .key  = 0x0141, .data = "L" },
    { .key  = 0x0142, .data = "l" },
    { .key  = 0x0143, .data = "N" },
    { .key  = 0x0144, .data = "n" },
    { .key  = 0x0145, .data = "N" },
    { .key  = 0x0146, .data = "n" },
    { .key  = 0x0147, .data = "N" },
    { .key  = 0x0148, .data = "n" },
    { .key  = 0x0149, .data = "'n" },
    { .key  = 0x014a, .data = "NG" },
    { .key  = 0x014b, .data = "ng" },
    { .key  = 0x014c, .data = "O" },
    { .key  = 0x014d, .data = "o" },
    { .key  = 0x014e, .data = "O" },
    { .key  = 0x014f, .data = "o" },
    { .key  = 0x0150, .data = "O" },
    { .key  = 0x0151, .data = "o" },
    { .key  = 0x0152, .data = "OE" },
    { .key  = 0x0153, .data = "oe" },
    { .key  = 0x0154, .data = "R" },
    { .key  = 0x0155, .data = "r" },
    { .key  = 0x0156, .data = "R" },
    { .key  = 0x0157, .data = "r" },
    { .key  = 0x0158, .data = "R" },
    { .key  = 0x0159, .data = "r" },
    { .key  = 0x015a, .data = "S" },
    { .key  = 0x015b, .data = "s" },
    { .key  = 0x015c, .data = "S" },
    { .key  = 0x015d, .data = "s" },
    { .key  = 0x015e, .data = "S" },
    { .key  = 0x015f, .data = "s" },
    { .key  = 0x0160, .data = "S" },
    { .key  = 0x0161, .data = "s" },
    { .key  = 0x0162, .data = "T" },
    { .key  = 0x0163, .data = "t" },
    { .key  = 0x0164, .data = "T" },
    { .key  = 0x0165, .data = "t" },
    { .key  = 0x0166, .data = "T" },
    { .key  = 0x0167, .data = "t" },
    { .key  = 0x0168, .data = "U" },
    { .key  = 0x0169, .data = "u" },
    { .key  = 0x016a, .data = "U" },
    { .key  = 0x016b, .data = "u" },
    { .key  = 0x016c, .data = "U" },
    { .key  = 0x016d, .data = "u" },
    { .key  = 0x016e, .data = "U" },
    { .key  = 0x016f, .data = "u" },
    { .key  = 0x0170, .data = "U" },
    { .key  = 0x0171, .data = "u" },
    { .key  = 0x0172, .data = "U" },
    { .key  = 0x0173, .data = "u" },
    { .key  = 0x0174, .data = "W" },
    { .key  = 0x0175, .data = "w" },
    { .key  = 0x0176, .data = "Y" },
    { .key  = 0x0177, .data = "y" },
    { .key  = 0x0178, .data = "Y" },
    { .key  = 0x0179, .data = "Z" },
    { .key  = 0x017a, .data = "z" },
    { .key  = 0x017b, .data = "Z" },
    { .key  = 0x017c, .data = "z" },
    { .key  = 0x017d, .data = "Z" },
    { .key  = 0x017e, .data = "z" },
    { .key  = 0x017f, .data = "s" },
    { .key  = 0x0180, .data = "b" },
    { .key  = 0x0181, .data = "B" },
    { .key  = 0x0182, .data = "B" },
    { .key  = 0x0183, .data = "b" },
    { .key  = 0x0184, .data = "B" },
    { .key  = 0x0185, .data = "b" },
    { .key  = 0x0186, .data = "O" },
    { .key  = 0x0187, .data = "C" },
    { .key  = 0x0188, .data = "c" },
    { .key  = 0x0189, .data = "D" },
    { .key  = 0x018a, .data = "D" },
    { .key  = 0x018b, .data = "D" },
    { .key  = 0x018c, .data = "d" },
    { .key  = 0x018d, .data = "z" },
    { .key  = 0x018e, .data = "E" },
    { .key  = 0x018f, .data = "E" },
    { .key  = 0x0190, .data = "E" },
    { .key  = 0x0191, .data = "F" },
    { .key  = 0x0192, .data = "f" },
    { .key  = 0x0193, .data = "G" },
    { .key  = 0x0194, .data = "Y" },
    { .key  = 0x0195, .data = "hv" },
    { .key  = 0x0196, .data = "I" },
    { .key  = 0x0197, .data = "I" },
    { .key  = 0x0198, .data = "K" },
    { .key  = 0x0199, .data = "k" },
    { .key  = 0x019a, .data = "l" },
    { .key  = 0x019b, .data = "l" },
    { .key  = 0x019c, .data = "w" },
    { .key  = 0x019d, .data = "N" },
    { .key  = 0x019e, .data = "n" },
    { .key  = 0x019f, .data = "O" },
    { .key  = 0x01a0, .data = "O" },
    { .key  = 0x01a1, .data = "o" },
    { .key  = 0x01a2, .data = "OI" },
    { .key  = 0x01a3, .data = "oi" },
    { .key  = 0x01a4, .data = "P" },
    { .key  = 0x01a5, .data = "p" },
    { .key  = 0x01a6, .data = "YR" },
    { .key  = 0x01a7, .data = "S" },
    { .key  = 0x01a8, .data = "s" },
    { .key  = 0x01a9, .data = "SH" },
    { .key  = 0x01aa, .data = "sh" },
    { .key  = 0x01ab, .data = "t" },
    { .key  = 0x01ac, .data = "T" },
    { .key  = 0x01ad, .data = "t" },
    { .key  = 0x01ae, .data = "T" },
    { .key  = 0x01af, .data = "U" },
    { .key  = 0x01b0, .data = "u" },
    { .key  = 0x01b1, .data = "Y" },
    { .key  = 0x01b2, .data = "V" },
    { .key  = 0x01b3, .data = "Y" },
    { .key  = 0x01b4, .data = "y" },
    { .key  = 0x01b5, .data = "Z" },
    { .key  = 0x01b6, .data = "z" },
    { .key  = 0x01b7, .data = "ZH" },
    { .key  = 0x01b8, .data = "ZH" },
    { .key  = 0x01b9, .data = "zh" },
    { .key  = 0x01ba, .data = "zh" },
    { .key  = 0x01bb, .data = "dz" },
    { .key  = 0x01bc, .data = "5" },
    { .key  = 0x01bd, .data = "5" },
    { .key  = 0x01be, .data = "ts" },
    { .key  = 0x01bf, .data = "w" },
    { .key  = 0x10348, .data = "hu" },
    { .key  = 0x01c4, .data = "DZ" },
    { .key  = 0x01c5, .data = "Dz" },
    { .key  = 0x01c6, .data = "dz" },
    { .key  = 0x01c7, .data = "LJ" },
    { .key  = 0x01c8, .data = "Lj" },
    { .key  = 0x01c9, .data = "lj" },
    { .key  = 0x01ca, .data = "NJ" },
    { .key  = 0x01cb, .data = "Nj" },
    { .key  = 0x01cc, .data = "nj" },
    { .key  = 0x01cd, .data = "A" },
    { .key  = 0x01ce, .data = "a" },
    { .key  = 0x01cf, .data = "I" },
    { .key  = 0x01d0, .data = "i" },
    { .key  = 0x01d1, .data = "O" },
    { .key  = 0x01d2, .data = "o" },
    { .key  = 0x01d3, .data = "U" },
    { .key  = 0x01d4, .data = "u" },
    { .key  = 0x01d5, .data = "U" },
    { .key  = 0x01d6, .data = "u" },
    { .key  = 0x01d7, .data = "U" },
    { .key  = 0x01d8, .data = "u" },
    { .key  = 0x01d9, .data = "U" },
    { .key  = 0x01da, .data = "u" },
    { .key  = 0x01db, .data = "U" },
    { .key  = 0x01dc, .data = "u" },
    { .key  = 0x01dd, .data = "e" },
    { .key  = 0x01de, .data = "A" },
    { .key  = 0x01df, .data = "a" },
    { .key  = 0x01e0, .data = "A" },
    { .key  = 0x01e1, .data = "a" },
    { .key  = 0x01e2, .data = "AE" },
    { .key  = 0x01e3, .data = "ae" },
    { .key  = 0x01e4, .data = "G" },
    { .key  = 0x01e5, .data = "g" },
    { .key  = 0x01e6, .data = "G" },
    { .key  = 0x01e7, .data = "g" },
    { .key  = 0x01e8, .data = "K" },
    { .key  = 0x01e9, .data = "k" },
    { .key  = 0x01ea, .data = "O" },
    { .key  = 0x01eb, .data = "o" },
    { .key  = 0x01ec, .data = "O" },
    { .key  = 0x01ed, .data = "o" },
    { .key  = 0x01ee, .data = "ZH" },
    { .key  = 0x01ef, .data = "zh" },
    { .key  = 0x01f0, .data = "j" },
    { .key  = 0x01f1, .data = "DZ" },
    { .key  = 0x01f2, .data = "Dz" },
    { .key  = 0x01f3, .data = "dz" },
    { .key  = 0x01f4, .data = "G" },
    { .key  = 0x01f5, .data = "g" },
    { .key  = 0x01f6, .data = "HU" },
    { .key  = 0x01f7, .data = "W" },
    { .key  = 0x01f8, .data = "N" },
    { .key  = 0x01f9, .data = "n" },
    { .key  = 0x01fa, .data = "A" },
    { .key  = 0x01fb, .data = "a" },
    { .key  = 0x01fc, .data = "AE" },
    { .key  = 0x01fd, .data = "ae" },
    { .key  = 0x01fe, .data = "O" },
    { .key  = 0x01ff, .data = "o" },
    { .key  = 0x0200, .data = "A" },
    { .key  = 0x0201, .data = "a" },
    { .key  = 0x0202, .data = "A" },
    { .key  = 0x0203, .data = "a" },
    { .key  = 0x0204, .data = "E" },
    { .key  = 0x0205, .data = "e" },
    { .key  = 0x0206, .data = "E" },
    { .key  = 0x0207, .data = "e" },
    { .key  = 0x0208, .data = "I" },
    { .key  = 0x0209, .data = "i" },
    { .key  = 0x020a, .data = "I" },
    { .key  = 0x020b, .data = "i" },
    { .key  = 0x020c, .data = "O" },
    { .key  = 0x020d, .data = "o" },
    { .key  = 0x020e, .data = "O" },
    { .key  = 0x020f, .data = "o" },
    { .key  = 0x0210, .data = "R" },
    { .key  = 0x0211, .data = "r" },
    { .key  = 0x0212, .data = "R" },
    { .key  = 0x0213, .data = "r" },
    { .key  = 0x0214, .data = "U" },
    { .key  = 0x0215, .data = "u" },
    { .key  = 0x0216, .data = "U" },
    { .key  = 0x0217, .data = "u" },
    { .key  = 0x0218, .data = "S" },
    { .key  = 0x0219, .data = "s" },
    { .key  = 0x021a, .data = "T" },
    { .key  = 0x021b, .data = "t" },
    { .key  = 0x021c, .data = "Y" },
    { .key  = 0x021d, .data = "y" },
    { .key  = 0x021e, .data = "H" },
    { .key  = 0x021f, .data = "h" },
    { .key  = 0x0220, .data = "N" },
    { .key  = 0x0221, .data = "d" },
    { .key  = 0x0222, .data = "OU" },
    { .key  = 0x0223, .data = "ou" },
    { .key  = 0x0224, .data = "Z" },
    { .key  = 0x0225, .data = "z" },
    { .key  = 0x0226, .data = "A" },
    { .key  = 0x0227, .data = "a" },
    { .key  = 0x0228, .data = "E" },
    { .key  = 0x0229, .data = "e" },
    { .key  = 0x022a, .data = "O" },
    { .key  = 0x022b, .data = "o" },
    { .key  = 0x022c, .data = "O" },
    { .key  = 0x022d, .data = "o" },
    { .key  = 0x022e, .data = "O" },
    { .key  = 0x022f, .data = "o" },
    { .key  = 0x0230, .data = "O" },
    { .key  = 0x0231, .data = "o" },
    { .key  = 0x0232, .data = "Y" },
    { .key  = 0x0233, .data = "y" },
    { .key  = 0x0234, .data = "l" },
    { .key  = 0x0235, .data = "n" },
    { .key  = 0x0236, .data = "t" },
    { .key  = 0x0237, .data = "j" },
    { .key  = 0x0238, .data = "db" },
    { .key  = 0x0239, .data = "qp" },
    { .key  = 0x023a, .data = "A" },
    { .key  = 0x023b, .data = "C" },
    { .key  = 0x023c, .data = "c" },
    { .key  = 0x023d, .data = "L" },
    { .key  = 0x023e, .data = "T" },
    { .key  = 0x023f, .data = "s" },
    { .key  = 0x0240, .data = "z" },
    { .key  = 0x0243, .data = "B" },
    { .key  = 0x0244, .data = "U" },
    { .key  = 0x0245, .data = "^" },
    { .key  = 0x0246, .data = "E" },
    { .key  = 0x0247, .data = "e" },
    { .key  = 0x0248, .data = "J" },
    { .key  = 0x0249, .data = "j" },
    { .key  = 0x024a, .data = "q" },
    { .key  = 0x024b, .data = "q" },
    { .key  = 0x024c, .data = "R" },
    { .key  = 0x024d, .data = "r" },
    { .key  = 0x024e, .data = "Y" },
    { .key  = 0x024f, .data = "y" },
    { .key  = 0x02c6, .data = "^" },
    { .key  = 0x1e9e, .data = "SS" },
    { .key  = 0x2000, .data = " " },
    { .key  = 0x2001, .data = " " },
    { .key  = 0x2002, .data = " " },
    { .key  = 0x2003, .data = " " },
    { .key  = 0x2004, .data = " " },
    { .key  = 0x2005, .data = " " },
    { .key  = 0x2006, .data = " " },
    { .key  = 0x2007, .data = " " },
    { .key  = 0x2008, .data = " " },
    { .key  = 0x2009, .data = " " },
    { .key  = 0x200a, .data = " " },
    { .key  = 0x200b, .data = " " },
    { .key  = 0x2010, .data = "-" },
    { .key  = 0x2011, .data = "-" },
    { .key  = 0x2012, .data = "-" },
    { .key  = 0x2013, .data = "-" },
    { .key  = 0x2014, .data = "-" },
    { .key  = 0x2015, .data = "-" },
    { .key  = 0x2017, .data = "_" },
    { .key  = 0x2018, .data = "'" },
    { .key  = 0x2019, .data = "'" },
    { .key  = 0x201a, .data = "'" },
    { .key  = 0x201b, .data = "'" },
    { .key  = 0x201c, .data = "\"" },
    { .key  = 0x201d, .data = "\"" },
    { .key  = 0x201e, .data = "\"" },
    { .key  = 0x201f, .data = "\"" },
    { .key  = 0x2020, .data = "+" },
    { .key  = 0x2021, .data = "++" },
    { .key  = 0x2022, .data = "*" },
    { .key  = 0x2024, .data = "." },
    { .key  = 0x2025, .data = ".." },
    { .key  = 0x2026, .data = "..." },
    { .key  = 0x2027, .data = "." },
    { .key  = 0x202f, .data = " " },
    { .key  = 0x2030, .data = "%" },
    { .key  = 0x2031, .data = "%" },
    { .key  = 0x2032, .data = "'" },
    { .key  = 0x2033, .data = "''" },
    { .key  = 0x2034, .data = "'''" },
    { .key  = 0x2035, .data = "`" },
    { .key  = 0x2036, .data = "``" },
    { .key  = 0x2037, .data = "```" },
    { .key  = 0x2038, .data = "^" },
    { .key  = 0x203b, .data = "*" },
    { .key  = 0x203c, .data = "!!" },
    { .key  = 0x203d, .data = "?" },
    { .key  = 0x203e, .data = "-" },
    { .key  = 0x203f, .data = "_" },
    { .key  = 0x2040, .data = "-" },
    { .key  = 0x2041, .data = "^" },
    { .key  = 0x2042, .data = "***" },
    { .key  = 0x2043, .data = "-" },
    { .key  = 0x2045, .data = "-[" },
    { .key  = 0x2046, .data = "]-" },
    { .key  = 0x2047, .data = "??" },
    { .key  = 0x2048, .data = "?!" },
    { .key  = 0x2049, .data = "!?" },
    { .key  = 0x204a, .data = "&" },
    { .key  = 0x204b, .data = "_pp_" },
    { .key  = 0x204e, .data = "*" },
    { .key  = 0x204f, .data = "[)" },
    { .key  = 0x2051, .data = "**" },
    { .key  = 0x2052, .data = "%" },
    { .key  = 0x2053, .data = "~" },
    { .key  = 0x2054, .data = "_" },
    { .key  = 0x2055, .data = "*" },
    { .key  = 0x2056, .data = "..." },
    { .key  = 0x2057, .data = "''''" },
    { .key  = 0x2058, .data = "...." },
    { .key  = 0x2059, .data = "....." },
    { .key  = 0x205a, .data = ".." },
    { .key  = 0x205b, .data = "...." },
    { .key  = 0x205d, .data = ":" },
    { .key  = 0x205e, .data = ":" },
    { .key  = 0x205f, .data = " " },
    { .key  = 0x2060, .data = " " },
    { .key  = 0x2122, .data = "_tm_" },
};

static struct translation_table builtin_unicode_table = {
    .length              = 594,
    .used                = 594,
    .max_data_length     = 7,
    .hits                = 0,
    .misses              = 0,
    .seeks               = 0,
    .overwrites          = 0,
    .use_hash            = 0,
    .builtin             = 1,
    .rows                = builtin_unicode_rows,
    .default_translation = "_",
};

struct translation_table *load_builtin_unicode_table(void)
{
    return table_resize(&builtin_unicode_table, 768, 1);
}

/**
 * Generated from cp1252.tbl.sample
 */

static struct translation_table_row builtin_cp1252_rows[10] = {
    { .key  = 0x0085, .data = "..." },
    { .key  = 0x0088, .data = "^" },
    { .key  = 0x008a, .data = "S" },
    { .key  = 0x008c, .data = "OE" },
    { .key  = 0x0096, .data = "-" },
    { .key  = 0x0097, .data = "-" },
    { .key  = 0x0099, .data = "_tm_" },
    { .key  = 0x009a, .data = "s" },
    { .key  = 0x009c, .data = "oe" },
    { .key  = 0x009f, .data = "Y" },
};

static struct translation_table builtin_cp1252_table = {
    .length              = 10,
    .used                = 10,
    .max_data_length     = 4,
    .hits                = 0,
    .misses              = 0,
    .seeks               = 0,
    .overwrites          = 0,
    .use_hash            = 0,
    .builtin             = 1,
    .rows                = builtin_cp1252_rows,
    .default_translation = NULL,
};

struct translation_table *load_builtin_cp1252_table(void)
{
    return table_resize(&builtin_cp1252_table, 256, 1);
}
