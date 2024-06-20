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
#define CSV_ALLOC _arena_context_alloc_noshare
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

#ifndef MAX_NAMES
#define MAX_NAME_CELL 120
#endif // MAX_NAMES

#ifndef SEPARATION_CARACTER
#define SEPARATION_CARACTER '.'
#define CONTINUATION_CARACTER ';'
#define SPACE_CARACTER " "
#endif

#endif // RDFTURTLE_PARSERC_H_
