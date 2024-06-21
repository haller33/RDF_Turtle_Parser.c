// MIT License
//
// Copyright (c) 2024 haller33
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#ifndef RDFTURTLE_PARSERC_H_
#define RDFTURTLE_PARSERC_H_

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef CUSTOM_ALLOC
#define CUSTOM_ALLOC
 // TODO: not need if follow power ten rule
// #define CSV_ALLOC _arena_context_alloc_noshare
#endif // CUSTOM_ALLOC

#ifndef CUSTOM_MALLOC_C
#define CUSTOM_MALLOC_C malloc
#endif // CUSTOM_MALLOC_C

#ifndef CUSTOM_FREE_MALLOC_C
#define CUSTOM_FREE_MALLOC_C free
#endif // CUSTOM_FREE_MALLOC_C

#ifndef JUST_MALLOC
#define JUST_MALLOC false
#endif // JUST_MALLOC

#ifndef SEPARATION_CARACTER
#define SEPARATION_CARACTER '.'
#define CONTINUATION_CARACTER ';'
#define SPACE_CARACTER " "
#endif // SEPARATION_CARACTER

#ifndef MAX_NAMES
#define MAX_NAMES
#define MAX_NAMESPACES 1500
#define MAX_NAME_CELL 2048
#define MAX_CHAR_BY_LINE 4500
#endif // MAX_NAMES

#ifndef SYMBOLS
#define SYMBOLS
#define BASE_URI_SYMBOL "@base"
#define PREFIX_SYMBOL "@prefix"
#endif // SYMBOLS

// try to align the stack, since DoD and TenPowerRule
//
typedef struct _rdf_turtle_adt {

    char subject[MAX_NAME_CELL];
    char predicate[MAX_NAME_CELL];
    char object[MAX_NAME_CELL];

    char _rdf_file_path[MAX_CHAR_BY_LINE];
    char _rdf_base_uri[MAX_CHAR_BY_LINE];
    char _namespaces[MAX_NAMESPACES][MAX_CHAR_BY_LINE]; // TODO
    char _current_line[MAX_CHAR_BY_LINE];

    size_t _triple_count;
    size_t _column;
    size_t _line_count_iterator;

    FILE *_pdp;

} rdf_turtle_adt;

#endif // RDFTURTLE_PARSERC_H_
