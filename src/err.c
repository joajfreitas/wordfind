#include <stdio.h>
#include <stdlib.h>
#include "err.h"

/*
 * TODO: Decidir error-checking por malloc ou wrapper
 * TODO: se por malloc lembrar de checkar TODOS os mallocs
*/

void err(char *error_message) {
	puts(error_message);
	exit(EXIT_FAILURE);
	return;
}

void *emalloc(size_t size)
{
    void *p = malloc(size);
    if (p==NULL) {
        puts("Erro: impossivel alocar memoria.");
        exit(EXIT_FAILURE);
    }
    return p;
}

FILE *efopen(char *filename, char *mode)
{
	FILE *fp = fopen(filename, mode);
	if (fp == NULL) {
		puts("Erro: impossivel abrir ficheiro");
		exit(EXIT_FAILURE);
	}
	return fp;
}
