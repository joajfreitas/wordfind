#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "err.h"
#include "word.h"
#include "file.h"

void read_dic(FILE *fdic, Lists_Array *la, int max_word_size)
{
	/* TODO: tamanho máximo das palavras do dic, perigo buffer*/
	char *buf = (char *) emalloc(max_word_size * sizeof(int));

	while (fscanf(fdic, "%s", buf) == 1) {
		la_new_node(la, w_new(buf), w_get_size(buf));
	}

	free(buf);
	fclose(fdic);
}

void read_pal(FILE *fpal, int max_word_size)
{
	char *word1 = (char *) malloc(max_word_size * sizeof(int));
	char *word2 = (char *) malloc(max_word_size * sizeof(int));

	int challenge;

	/* Verificar apenas por um novo problema (um por linha);
	 * assume-se que o ficheiro está formatado corretamente,
	 * por isso não se verificam os fscanf() dentro do ciclo. */
	while (fscanf(fpal, "%s", word1) == 1) {
		fscanf(fpal, "%s", word2);
		fscanf(fpal, "%d", &challenge);
		/* TODO: ou guardar os problemas ou resolver um por um */
	}

	free(word1);
	free(word2);
	fclose(fpal);
}
