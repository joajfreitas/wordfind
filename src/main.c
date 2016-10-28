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

int main(int argc, char *argv[])
{
	Lists_Array *la;
	FILE *fdic, *fpal;
	int i;
	char *test;
	int max_word_size;
	int *word_exists;

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

	word_exists = (int *) calloc(1024,  sizeof(int));
	max_word_size = (int) find_max_word(fpal, word_exists) + 1;
	rewind(fdic);

	/* Ler dicinário para um array de listas */
	/* TODO: tamanho máximo das palavras */
	la = la_init(max_word_size);
	read_dic(fdic, la, max_word_size, word_exists);
	la_convert_to_array(la);

	/* Ler problemas */
	/* TODO: os problemas são resolvidos um a um assim que são lidos,
	 * ou são resolvidos todos de seguida e escritos duma vez
	 * no ficheiro de saída? */
	read_pal(fpal, max_word_size);

	/* Libertar memória */
	free(word_exists);
	la_free(la, w_free);

	return EXIT_SUCCESS;
}
