#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "err.h"
#include "const.h"
#include "file.h"
#include "word.h"

const char *VALID_EXTS[] = {".dic", ".pal"};

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
	int *word_sizes;

	/* Verificação dos parametros de entrada*/

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

	/* Leitura de ficheiros de entrada */
	word_sizes = find_word_sizes(fpal);
	rewind(fpal);

	/* Inicializar array de listas */
	la = la_init(word_sizes);
	free(word_sizes);

	/* Ler dicinário para o array de listas */
	read_dic(fdic, la);
	fclose(fdic);

	/* Ordenar listas do array de listas */
	la_sort_lists(la);

	/* Converter cada lista do array de listas para array.
	 * Assim "la" é um array de arrays e possibilita procura binária. */
	la_convert_to_array(la);

	/* Ler e resolver problemas */
	solve_pal(fpal, la);
	fclose(fpal);

	/* Libertar memória */
	la_free(la, w_free);

	return EXIT_SUCCESS;
}
