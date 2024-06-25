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

#ifndef RDFTURTLE_CUSTOM_ALLOC
#define RDFTURTLE_CUSTOM_ALLOC
 // TODO: not need if follow power ten rule
// #define CSV_ALLOC _arena_context_alloc_noshare
#endif // RDFTURTLE_CUSTOM_ALLOC

#ifndef RDFTURTLE_CUSTOM_MALLOC_C
#define RDFTURTLE_CUSTOM_MALLOC_C malloc
#endif // RDFTURTLE_CUSTOM_MALLOC_C

#ifndef RDFTURTLE_CUSTOM_FREE_MALLOC_C
#define RDFTURTLE_CUSTOM_FREE_MALLOC_C free
#endif // RDFTURTLE_CUSTOM_FREE_MALLOC_C

#ifndef RDFTURTLE_JUST_MALLOC
#define RDFTURTLE_JUST_MALLOC false
#endif // RDFTURTLE_JUST_MALLOC

#ifndef RDFTURTLE_COMMENT_CARACTER
#define RDFTURTLE_COMMENT_CARACTER '#'
#endif

#ifndef RDFTURTLE_SEPARATION_CARACTER
#define RDFTURTLE_TRIPLE_SEPARATION_CARACTER '.'
#define RDFTURTLE_CONTINUATION_PREDICATE_LIST_CARACTER ','
#define RDFTURTLE_CONTINUATION_OBJECT_LIST_CARACTER ';'
#define RDFTURTLE_SPACE_CARACTER " "
#endif // RDFTURTLE_SEPARATION_CARACTER

#ifndef RDFTURTLE_MAX_NAMES
#define RDFTURTLE_MAX_NAMES
/// the max caracters for a URL in HTTP 1.1 is
/// since standard RFC 2616, 2048 caracters...
/// but since new update on standard (RFC 7230, RFC 9110 section 4.1),
/// and tests on browsers... (like google chrome)
/// they can be up to 8000 caracters
/// each cell can be a URI, so
/// source :: https://stackoverflow.com/questions/417142/what-is-the-maximum-length-of-a-url-in-different-browsers#answer-417184
#define RDFTURTLE_MAX_NAME_CELL 8192 // 2 ^ 13
#define RDFTURTLE_MAX_CHAR_BY_LINE 25088 // ((8192 × 3) + 512)
/// since there is no more wish to handle and keep data of the namespaces on the internal adt of the parser
/// #define RDFTURTLE_MAX_NAMESPACES 1500 // arbitrary one...
#endif // RDFTURTLE_MAX_NAMES

#ifndef RDFTURTLE_SYMBOLS
#define RDFTURTLE_SYMBOLS
#define RDFTURTLE_BEGIN_SYMBOL "@"
#define RDFTURTLE_BASE_URI_SYMBOL_RDF11 "@base"
#define RDFTURTLE_PREFIX_SYMBOL_RDF11 "@prefix"
#define RDFTURTLE_BASE_URI_SYMBOL_SPARQL "BASE"
#define RDFTURTLE_PREFIX_SYMBOL_SPARQL "PREFIX"
#endif // RDFTURTLE_SYMBOLS

/// return structure
//
typedef struct _rdf_turtle_adt_ret {

    char rdf_base_url[RDFTURTLE_MAX_NAME_CELL];
    char rdf_current_namespace[RDFTURTLE_MAX_NAME_CELL];
    char rdf_current_prefix[RDFTURTLE_MAX_NAME_CELL];
    char rdf_subject[RDFTURTLE_MAX_NAME_CELL];
    char rdf_predicate[RDFTURTLE_MAX_NAME_CELL];
    char rdf_object[RDFTURTLE_MAX_NAME_CELL];

} rdf_turtle_adt_ret;

/// try to align the stack, since DoD and TenPowerRule
//
typedef struct _rdf_turtle_adt {

    size_t _triple_count;
    size_t _caracter_count;
    size_t _current_name_space_count;
    size_t _current_line_count_iterator;

    char subject[RDFTURTLE_MAX_NAME_CELL];
    char predicate[RDFTURTLE_MAX_NAME_CELL];
    char object[RDFTURTLE_MAX_NAME_CELL];

    char _rdf_file_path[RDFTURTLE_MAX_NAME_CELL];
    char _rdf_base_uri[RDFTURTLE_MAX_NAME_CELL];
    char _current_namespace[RDFTURTLE_MAX_NAME_CELL];
    char _current_line[RDFTURTLE_MAX_CHAR_BY_LINE];

    FILE *_pdp;

} rdf_turtle_adt;

#endif // RDFTURTLE_PARSERC_H_

#ifndef RDFTURTLE_PARSERC_IMPLEMENTATION
#define RDFTURTLE_PARSERC_IMPLEMENTATION



#endif // RDFTURTLE_PARSERC_IMPLEMENTATION
