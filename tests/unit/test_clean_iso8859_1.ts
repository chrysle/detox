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

#define DATA_COUNT 5
static struct test_filename data[DATA_COUNT] = {
    // legacy

    { .filename = "safe string",            .expected = "safe string" },
    { .filename = "\xAE reg",               .expected = "_reg_ reg" },
    { .filename = "\xA9 copy",              .expected = "_copy_ copy" },
    { .filename = "\xC6 capital AE",        .expected = "AE capital AE" },
    { .filename = "\xDE capital thorn",     .expected = "TH capital thorn" },
};

#test test_clean_iso8859_1
    struct clean_string_options *options;
    char *output;
    int i;

    options = new_clean_string_options();
    options->translation_table = load_builtin_iso8859_1_table();

    // legacy tests
    for (i = 0; i < DATA_COUNT; i++) {
        output = clean_iso8859_1(data[i].filename, options);
        ck_assert_str_eq(output, data[i].expected);
    }

    // confirm NULL works
    output = clean_iso8859_1(NULL, NULL);
    ck_assert(output == NULL);

#test-exit(1) test_clean_iso8859_1_missing_options
    clean_iso8859_1("what", NULL);