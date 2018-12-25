// Copyright © 2016-2017 Alison Sanderson, all rights reserved.
#ifndef lith_file_h
#define lith_file_h

#include <stdio.h>

#define W_Find(name) ServCallI(s"FindLump", name)
#define W_Read(lmp)  ServCallS(s"ReadLump", lmp)

#define FEOF(fp) ((fp)->_flag & _FILEFLAG_EOF)

FILE *W_Open(__str fname, char const *rw);
FILE *Lith_NFOpen(int pnum, __str pcvar, char rw);
size_t Lith_FWrite32(void const *restrict ptr, size_t count, size_t bytes, FILE *restrict fp);
size_t Lith_FWrite(void const *restrict ptr, size_t count, FILE *restrict fp);
size_t Lith_FWrite_str(void const __str_ars *restrict ptr, size_t count, FILE *restrict fp);
size_t Lith_FRead32(void *restrict buf, size_t count, size_t bytes, FILE *restrict fp);

#endif

