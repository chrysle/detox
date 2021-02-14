/**
 * This file is part of the Detox package.
 *
 * Copyright (c) Doug Harple <detox.dharple@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 */

#ifndef __BUILTIN_TABLE_H
#define __BUILTIN_TABLE_H

#include "table.h"

extern struct translation_table * load_builtin_safe_table();
extern struct translation_table * load_builtin_iso8859_1_table();
extern struct translation_table * load_builtin_unicode_table();

#endif /* __BUILTIN_TABLE_H */