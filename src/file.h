#ifndef _UTILS_H
#define _UTILS_H

#include "lists_array.h"

int *find_max_word(FILE *fdic);
void read_pal(FILE *fpal, int max_word_size);
void read_dic(FILE *fdic, Lists_Array *la);

#endif
