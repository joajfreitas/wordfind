#ifndef _UTILS_H
#define _UTILS_H

#include "lists_array.h"

int *find_max_word(FILE *fdic);
void read_pal(FILE *fpal, Lists_Array *la);
void read_dic(FILE *fdic, Lists_Array *la);

#endif
