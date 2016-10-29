#ifndef _ERR_H
#define _ERR_H

#include <stdlib.h>
#include <stdio.h>

void *emalloc(size_t size);
void *ecalloc(size_t nmemb, size_t size);
FILE *efopen(char *filename, char *mode);

#endif
