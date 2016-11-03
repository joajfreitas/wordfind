#ifndef _UTILS_H
#define _UTILS_H

#include "lists_array.h"

int *find_word_sizes(FILE *fpal);

void read_dic(FILE *fdic, Lists_Array *la);

void solve_pal(FILE *fpal, Lists_Array *la);

#endif
