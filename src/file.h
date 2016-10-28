#ifndef _UTILS_H
#define _UTILS_H

#include "lists_array.h"

size_t find_max_word(FILE *fdic, int *word_exists);
void read_pal(FILE *fpal, int max_word_size);
void read_dic(FILE *fdic, Lists_Array *la, int max_word_size, int *word_exists);

#endif
