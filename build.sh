#!/bin/bash
CFLAGS="-Wall -Wextra -Wshadow -Werror -std=c99 -pedantic"
clang $CFLAGS -o rdfparser.bin src/main.c
