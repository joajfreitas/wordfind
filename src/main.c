#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "err.h"
#include "const.h"
#include "file.h"
#include "word.h"


void usage(char *nomeProg) {
	fprintf(stderr, "Uso: %s [dicionário.dic] [problemas.pal]\n", nomeProg);
	exit(EXIT_FAILURE);
}

typedef struct _Matrix {
	char ***words;
	int *array_sizes; /* columns */
	int max_word_size; /* lines */
} Matrix;

Matrix *matrix_init()
{
	Matrix *matrix = (Matrix *) emalloc(sizeof(Matrix));
	return matrix;
}

void matrix_free(Matrix *matrix)
{
	int i, j;
	for (i = 0; i < matrix->max_word_size; i++) {
		for (j = 0; j < matrix->array_sizes[i]; j++ ) {
			free(matrix->words[i][j]);
		}
		free(matrix->words[i]);
	}
	free(matrix->words);
	free(matrix->array_sizes);
	free(matrix);
}

void read_dic_naive(FILE *fdic, Matrix *matrix)
{
	int i;
	char *buf = (char *) emalloc((1024 + 1) * sizeof(char));
	int max_word_size = 0;
	char ***words;
	int *array_sizes;
	int *d;
	char *word;

	while (fscanf(fdic, "%s", buf) == 1) {
		i = strlen(buf);
		if (i > max_word_size)
			max_word_size = i;
	}
	max_word_size++;

	words = (char ***) emalloc(max_word_size * sizeof(char **));
	array_sizes = (int *) calloc(max_word_size, sizeof(int));

	rewind(fdic);
	while (fscanf(fdic, "%s", buf) == 1) {
		array_sizes[strlen(buf)]++;
	}

	for (i = 0; i < max_word_size; i++) {
		words[i] = (char **) emalloc(array_sizes[i] * sizeof(char *));
	}

	d = (int *) emalloc(max_word_size * sizeof(int));
	for (i = 0; i < max_word_size; i++) {
		d[i] = array_sizes[i] - 1;
	}

	rewind(fdic);
	while (fscanf(fdic, "%s", buf) == 1) {
		word = (char *) emalloc((strlen(buf) + 1) * sizeof(char));
		strcpy(word, buf);
		words[strlen(word)][d[strlen(word)]--] = word;
	}

	free(buf);
	free(d);
	fclose(fdic);

	matrix->words = words;
	matrix->array_sizes = array_sizes;
	matrix->max_word_size = max_word_size;
}

int main(int argc, char *argv[])
{
	FILE *fdic, *fpal;
	int i;
	char *test;

	Matrix *matrix;

	if (argc != 3) {
		usage(argv[0]);
	}

	/* Verificar extensões dos ficheiros */
	for (i = 0; i < 2; i++) {
		test = strrchr(argv[i+1], '.');

		if (strcmp(test, VALID_EXTS[i]) != 0) {
			usage(argv[1]);
		}
	}

	/* Abrir ficheiros de entrada (efopen faz exit() em caso de erro) */
	fdic = efopen(argv[1], "r");
	fpal = efopen(argv[2], "r");

	matrix = matrix_init();
	read_dic_naive(fdic, matrix);

	/* Ler problemas */
	/* TODO: os problemas são resolvidos um a um assim que são lidos,
	 * ou são resolvidos todos de seguida e escritos duma vez
	 * no ficheiro de saída? */
	read_pal(fpal, MAX_WORD_SIZE);

	matrix_free(matrix);

	return EXIT_SUCCESS;
}
