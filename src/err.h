#ifndef _ERR_H
#define _ERR_H

#include <stdlib.h>
#include <stdio.h>

void *emalloc(const size_t size);
void *ecalloc(const size_t nmemb, const size_t size);
FILE *efopen(const char *filename, const char *mode);

#endif
