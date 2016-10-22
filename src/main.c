#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists_array.h"
#include "err.h"
#include "const.h"


/* TODO: from here... */
void free_word(Item word)
{
	free(word);
}
void read_dic(FILE *fdic, Lists_Array *la)
{
	/* TODO: tamanho máximo das palavras do dic, perigo buffer */
	char word[MAX_WORD_SIZE];

	while (fscanf(fdic, "%s", word) == 1) {
		la_save_word(la, word);
	}

	fclose(fdic);
}
void read_pal(FILE *fpal)
{
	char word1[MAX_WORD_SIZE];
	char word2[MAX_WORD_SIZE];
	int challenge;

	/* Verificar apenas por um novo problema (um por linha);
	 * assume-se que o ficheiro está formatado corretamente,
	 * por isso não se verificam os fscanf() dentro do ciclo. */
	while (fscanf(fpal, "%s", word1) == 1) {
		fscanf(fpal, "%s", word2);
		fscanf(fpal, "%d", &challenge);
		/* TODO: ou guardar os problemas ou resolver um por um */
	}

	fclose(fpal);
}
/* TODO: ...to here needs to be moved*/


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

		if (strcmp(test, VALID_EXTS[i]) != 0) {
			usage(argv[1]);
		}
	}

	/* Abrir ficheiros de entrada (efopen faz exit() em caso de erro) */
	fdic = efopen(argv[1], "r");
	fpal = efopen(argv[2], "r");

	/* Ler dicinário para um array de listas */
	/* TODO: tamanho máximo das palavras */
	la = la_init(MAX_WORD_SIZE);
	read_dic(fdic, la);

	/* Ler problemas */
	/* TODO: os problemas são resolvidos um a um assim que são lidos,
	 * ou são resolvidos todos de seguida e escritos duma vez
	 * no ficheiro de saída? */
	read_pal(fpal);

	/* Libertar memória */
	la_free(la, free_word);

	return EXIT_SUCCESS;
}
