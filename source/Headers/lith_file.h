// Copyright © 2016-2017 Graham Sanderson, all rights reserved.
#ifndef LITH_FILE_H
#define LITH_FILE_H

#include <stdio.h>

FILE *Lith_NFOpen(int pnum, __str pcvar, char rw);
size_t Lith_FWrite32(void const *restrict ptr, size_t count, size_t bytes, FILE *restrict fp);
size_t Lith_FWrite_str(void const __str_ars *restrict ptr, size_t count, FILE *restrict fp);
size_t Lith_FRead32(void *restrict buf, size_t count, size_t bytes, FILE *restrict fp);

#endif

