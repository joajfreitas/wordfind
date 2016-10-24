#include <stdio.h>
#include <stdlib.h>

#include "err.h"

void *emalloc(size_t size)
{
	void *p = malloc(size);
	if (p == NULL) {
		fprintf(stderr, "Erro: impossível alocar memória.");
		exit(EXIT_FAILURE);
	}
	return p;
}

FILE *efopen(char *filename, char *mode)
{
	FILE *fp = fopen(filename, mode);
	if (fp == NULL) {
		fprintf(stderr, "Erro: impossível abrir ficheiro %s.", filename);
		exit(EXIT_FAILURE);
	}
	return fp;
}
