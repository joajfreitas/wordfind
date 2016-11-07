#ifndef _UTILS_H
#define _UTILS_H

#include "lists_array.h"

int *find_word_sizes(FILE *fpal);

void read_dic(FILE *fdic, Lists_Array *la);

char *change_file_ext(char *s, char *new_ext, size_t ext_size);
void solve_pal(FILE *fpal, FILE *fstat, Lists_Array *la);

#endif
