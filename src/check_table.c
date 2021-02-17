/**
 * This file is part of the Detox package.
 *
 * Copyright (c) Doug Harple <detox.dharple@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

/**
 * Helper utility to review tables.
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>

#include "table.h"
#include "table_dump.h"
#include "builtin_table.h"

enum {
    BASE_STATE,
    INSIDE_STATE
};

static struct translation_table *check_table(char *filename, int use_hash)
{
    FILE *ttable_file;
    char *work;
    int code;
    int offset;
    char *parsed;
    int err;
    int size;
    int max_data_length;
    int ret;
    int state;
    int last;
    char *check;

    struct translation_table *table;

    struct stat ttable_stat;

    err = stat(filename, &ttable_stat);
    if (err == -1) {
        return NULL;
    }

    if (ttable_stat.st_size > 0) {
        size = ttable_stat.st_size;
    } else {
        size = (512 * ttable_stat.st_blocks);
    }

    size /= 6;

    if (size < 500) {
        size = 500;
    }

    table = table_init(size);
    if (table == NULL) {
        return NULL;
    }

    table->use_hash = use_hash;

    ttable_file = fopen(filename, "r");
    if (ttable_file == NULL) {
        fprintf(stderr, "Unable to open translation table: %s\n", strerror(errno));
        return NULL;
    }

    work = malloc(1024);
    if (work == NULL) {
        fprintf(stderr, "Unable to allocate memory: %s\n", strerror(errno));
        fclose(ttable_file);
        return NULL;
    }

    parsed = malloc(1024);
    if (parsed == NULL) {
        fprintf(stderr, "Unable to allocate memory: %s\n", strerror(errno));
        fclose(ttable_file);
        free(work);
        return NULL;
    }

    last = 0;

    max_data_length = 1;
    state = BASE_STATE;

    while (fgets(work, 1024, ttable_file) != NULL) {
        if (*work == '#') {

            /*
             * Don't even bother
             */
            continue;
        }

        parsed[0] = '\0';

        if (state == BASE_STATE) {
            ret = sscanf(work, " %s %n", parsed, &offset);

            if (ret == 0) {
                continue;
            }

            if (strncasecmp(parsed, "start", 5) == 0) {
                last = 0;

                if (work[offset] == '\0') {
                    // All languages
                    state = INSIDE_STATE;
                    continue;
                }

                if (work[offset] == '"') {
                    sscanf(work + offset + 1, "%[^\"]", parsed);
                } else if (work[offset] == '\'') {
                    sscanf(work + offset + 1, "%[^']", parsed);
                } else {
                    sscanf(work + offset, "%s", parsed);
                }

                printf("skipping language subsection for %s\n", parsed);

                continue;
            }

            if (strncasecmp(parsed, "default", 7) == 0) {

                if (work[offset] == '\0') {
                    table->default_translation = NULL;
                    continue;
                }

                if (work[offset] == '"') {
                    sscanf(work + offset + 1, "%[^\"]", parsed);
                } else if (work[offset] == '\'') {
                    sscanf(work + offset + 1, "%[^']", parsed);
                } else {
                    sscanf(work + offset, "%s", parsed);
                }

                table->default_translation = strdup(parsed);

                if (strlen(parsed) > max_data_length) {
                    max_data_length = strlen(parsed);
                }

                continue;
            }

            continue;
        }

        /*
         * Inside state
         */

        code = -1;

        ret = sscanf(work, "%i %n", &code, &offset);

        if (ret == 0 || code < 0 || offset < 0) {

            /*
             * Check for end
             */
            ret = sscanf(work, " %s %n", parsed, &offset);

            if (ret > 0 && strncasecmp(parsed, "end", 5) == 0) {
                state = BASE_STATE;
            }

            continue;
        }

        if (work[offset] == '\0') {
            continue;
        }

        if (work[offset] == '"') {
            sscanf(work + offset + 1, "%[^\"]", parsed);
        } else if (work[offset] == '\'') {
            sscanf(work + offset + 1, "%[^']", parsed);
        } else {
            sscanf(work + offset, "%s", parsed);
        }

        ret = table_put(table, code, parsed);
        if (ret == -1) {
            fprintf(stderr, "Failed to add row 0x%04x \"%s\" to translation table\n", code, parsed);
            table_free(table);
            fclose(ttable_file);
            free(work);
            free(parsed);
            return NULL;
        }

        check = table_get(table, code);
        if (check == NULL || strcmp(parsed, check) != 0) {
            fprintf(stderr, "Failed to retrieve row 0x%04x \"%s\" in translation table\n", code, parsed);
            table_free(table);
            fclose(ttable_file);
            free(work);
            free(parsed);
            return NULL;
        }

        if (strlen(parsed) > max_data_length) {
            max_data_length = strlen(parsed);
        }

        if (code < last) {
            printf("warning - code 0x%04X appears after 0x%04X\n", code, last);
        } else if (code == last) {
            printf("warning - code 0x%04X appears twice in a row\n", code);
        }
        last = code;
    }

    table->max_data_length = max_data_length;

    free(work);
    free(parsed);
    fclose(ttable_file);

    return table;
}

static struct translation_table *check_table_again(char *filename, struct translation_table *source)
{
    FILE *ttable_file;
    char *work;
    int code;
    int offset;
    char *parsed;
    int err;
    int ret;
    int state;
    char *check;

    struct translation_table *table;

    struct stat ttable_stat;

    err = stat(filename, &ttable_stat);
    if (err == -1) {
        return NULL;
    }

    table = table_resize(source, ((int) ceil(source->used / BUILTIN_TABLE_MULTIPLE) + 1) * BUILTIN_TABLE_MULTIPLE, 1);

    if (table == NULL) {
        return NULL;
    }

    ttable_file = fopen(filename, "r");
    if (ttable_file == NULL) {
        fprintf(stderr, "Unable to open translation table: %s\n", strerror(errno));
        return NULL;
    }

    work = malloc(1024);
    if (work == NULL) {
        fprintf(stderr, "Unable to allocate memory: %s\n", strerror(errno));
        fclose(ttable_file);
        return NULL;
    }

    parsed = malloc(1024);
    if (parsed == NULL) {
        fprintf(stderr, "Unable to allocate memory: %s\n", strerror(errno));
        fclose(ttable_file);
        free(work);
        return NULL;
    }

    state = BASE_STATE;

    while (fgets(work, 1024, ttable_file) != NULL) {
        if (*work == '#') {

            /*
             * Don't even bother
             */
            continue;
        }

        parsed[0] = '\0';

        if (state == BASE_STATE) {
            ret = sscanf(work, " %s %n", parsed, &offset);

            if (ret == 0) {
                continue;
            }

            if (strncasecmp(parsed, "start", 5) == 0) {
                if (work[offset] == '\0') {
                    // All languages
                    state = INSIDE_STATE;
                    continue;
                }

                if (work[offset] == '"') {
                    sscanf(work + offset + 1, "%[^\"]", parsed);
                } else if (work[offset] == '\'') {
                    sscanf(work + offset + 1, "%[^']", parsed);
                } else {
                    sscanf(work + offset, "%s", parsed);
                }

                printf("skipping language subsection for %s\n", parsed);

                continue;
            }

            if (strncasecmp(parsed, "default", 7) == 0) {
                continue;
            }

            continue;
        }

        /*
         * Inside state
         */

        code = -1;

        ret = sscanf(work, "%i %n", &code, &offset);

        if (ret == 0 || code < 0 || offset < 0) {

            /*
             * Check for end
             */
            ret = sscanf(work, " %s %n", parsed, &offset);

            if (ret > 0 && strncasecmp(parsed, "end", 5) == 0) {
                state = BASE_STATE;
            }

            continue;
        }

        if (work[offset] == '\0') {
            continue;
        }

        if (work[offset] == '"') {
            sscanf(work + offset + 1, "%[^\"]", parsed);
        } else if (work[offset] == '\'') {
            sscanf(work + offset + 1, "%[^']", parsed);
        } else {
            sscanf(work + offset, "%s", parsed);
        }

        check = table_get(table, code);
        if (check == NULL || strcmp(parsed, check) != 0) {
            fprintf(stderr, "Failed to retrieve row 0x%04x \"%s\" in resized translation table\n", code, parsed);
            table_free(table);
            fclose(ttable_file);
            free(work);
            free(parsed);
            return NULL;
        }
    }

    free(work);
    free(parsed);
    fclose(ttable_file);

    return table;
}

int main(int argc, char **argv)
{
    struct translation_table *table;
    int optcode;
    int builtin = 0;
    int dump = 0;
    int use_hash = 1;
    int verbose = 0;

    while ((optcode = getopt(argc, argv, "bdlhv")) != -1) {
        switch (optcode) {
            case 'b': // simulate a builtin table
                builtin = 1;
                break;

            case 'd':
                dump = 1;
                break;

            case 'h':
                printf("check-table [-bdlhv] filename.tbl\n");
                return 0;

            case 'l': // linear
                use_hash = 0;
                break;

            case 'v':
                verbose = 1;
                break;

            default:
                fprintf(stderr, "unknown option: %c\n", optcode);
                return -1;
        }
    }

    if (optind < argc) {
        printf("checking: %s\n", argv[optind]);
        table = check_table(argv[optind], use_hash);
        if (builtin) {
            table = check_table_again(argv[optind], table);
        }
        if (table) {
            if (dump) {
                table_dump(table, verbose);
            }
            table_stats(table);
        }
    } else {
        printf("please specify a file to operate on\n");
        return -1;
    }

    return 0;
}
