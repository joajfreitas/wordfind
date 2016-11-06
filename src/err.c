#include <stdio.h>
#include <stdlib.h>

#include "err.h"

void *emalloc(const size_t size)
{
	void *p = malloc(size);
	if (p == NULL) {
		fprintf(stderr, "Erro: impossível alocar memória.\n");
		exit(EXIT_FAILURE);
	}
	return p;
}

void *ecalloc(const size_t nmemb, const size_t size)
{
	void *p = calloc(nmemb, size);
	if (p == NULL) {
		fprintf(stderr, "Erro: impossivel alocar memória.\n");
		exit(EXIT_FAILURE);
	}
	return p;
}

FILE *efopen(const char *filename, const char *mode)
{
	FILE *fp = fopen(filename, mode);
	if (fp == NULL) {
		fprintf(stderr, "Erro: impossível abrir ficheiro %s.\n", filename);
		exit(EXIT_FAILURE);
	}
	return fp;
}
