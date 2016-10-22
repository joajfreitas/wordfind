#include <stdio.h>
#include <stdlib.h>
#include "lists_array.h"
#include "err.h"

#define MAX_WORD_SIZE 30

void usage(char *nomeProg) {
	printf("Uso: %s [dicionário.dic] [problemas.pal]\n", nomeProg);
	exit(EXIT_FAILURE);
}

void read_dic(char *filename, Lists_Array *la)
{
	FILE *fdic = efopen(filename, "r");
	/* TODO: tamanho máximo das palavras do dic, perigo buffer */
	char word[MAX_WORD_SIZE];

	while (fscanf(fdic, "%s", word) == 1) {
		la_save_word(la, word);
	}

	fclose(fdic);
}


void free_word(Item word)
{
	free(word);
}


int main(int argc, char *argv[])
{
	Lists_Array *la;

	if (argc != 3) {
		usage(argv[0]);
	}

	/* TODO: tamanho máximo das palavras */
	la = la_init(MAX_WORD_SIZE);
	read_dic(argv[1], la);

	la_free(la, free_word);

	return EXIT_SUCCESS;
}
