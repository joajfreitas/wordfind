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

	if (argc != 3) {
		usage(argv[0]);
	}

	/* Verificar extensões dos ficheiros */
	for (i = 0; i < 2; i++) {
		test = strrchr(argv[i+1], '.');

		if (!test || strcmp(test, VALID_EXTS[i]) != 0) {
			usage(argv[1]);
		}
	}

	/* Abrir ficheiros de entrada (efopen faz exit() em caso de erro) */
	fdic = efopen(argv[1], "r");
	fpal = efopen(argv[2], "r");

	/* Ler dicinário para um array de listas */
	/* TODO: tamanho máximo das palavras */
	la = la_init(MAX_WORD_SIZE);
	read_dic(fdic, la, MAX_WORD_SIZE);

	/* Ler problemas */
	/* TODO: os problemas são resolvidos um a um assim que são lidos,
	 * ou são resolvidos todos de seguida e escritos duma vez
	 * no ficheiro de saída? */
	read_pal(fpal, MAX_WORD_SIZE);

	/* Libertar memória */
	la_free(la, w_free);

	return EXIT_SUCCESS;
}
