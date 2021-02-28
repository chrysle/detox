/**
 * This file is part of the Detox package.
 *
 * Copyright (c) Doug Harple <detox.dharple@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "builtin_table.h"
#include "clean_string.h"
#include "detox_struct.h"

#include "unit_struct.h"

#define DATA_COUNT 15
static struct test_filename data[DATA_COUNT] = {
    // legacy

    { .filename = "safe string",                    .expected = "safe string" },
    { .filename = "\u00AE reg",                     .expected = "_reg_ reg" },
    { .filename = "\u00A9 copy",                    .expected = "_copy_ copy" },
    { .filename = "\u00C6 capital AE",              .expected = "AE capital AE" },
    { .filename = "\u00DE capital thorn",           .expected = "TH capital thorn" },
    { .filename = "\u014A capital ENG",             .expected = "NG capital ENG" },
    { .filename = "\u0172 capital U with Ogonek",   .expected = "U capital U with Ogonek" },

    // github issue 40

    { .filename = "_ () whatever",                  .expected = "_ () whatever" },
    { .filename = "\u4000 ignore",                  .expected = "_ ignore" },
    { .filename = "\x7F delete",                    .expected = "_ delete" },
    // 2 byte UTF-8 encoded 0x00 (null)
    { .filename = "\xC0\x80 null",                  .expected = "_hidden_null_ null" },
    // 2 byte UTF-8 encoded 0x20 (space)
    { .filename = "\xC0\xA0 space",                 .expected = "  space" },
    // 2 byte UTF-8 encoded 0x30 (zero) 
    { .filename = "\xC0\xB0 zero",                  .expected = "0 zero" },
    // 2 byte UTF-8 encoded 0x7E (tilde)
    { .filename = "\xC1\xBE tilde",                 .expected = "~ tilde" },
    // 2 byte UTF-8 encoded 0x7F (tilde)
    { .filename = "\xC1\xBF delete",                .expected = "_ delete" },
};

#test test_clean_utf_8
    struct clean_string_options *options;
    char *output;
    int i;

    options = new_clean_string_options();
    options->translation_table = load_builtin_unicode_table();

    // legacy tests
    for (i = 0; i < DATA_COUNT; i++) {
        output = clean_utf_8(data[i].filename, options);
        ck_assert_str_eq(output, data[i].expected);
    }

    // confirm NULL works
    output = clean_utf_8(NULL, NULL);
    ck_assert(output == NULL);

#test-exit(1) test_clean_utf_8_missing_options
    clean_utf_8("what", NULL);