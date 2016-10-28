#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "err.h"
#include "word.h"
#include "file.h"


size_t find_max_word(FILE *fpal, int *word_exists)
{
	char buffer[1024];
	size_t max = 0, size=0;

	while (fscanf(fpal, "%s", buffer) == 1) {
		size = strlen(buffer);
		if (max < size) max = strlen(buffer);
		(word_exists[size])++;
	}
	return max;
}


void read_dic(FILE *fdic, Lists_Array *la, int max_word_size, int *word_exists)
{
	/* TODO: tamanho máximo das palavras do dic, perigo buffer*/
	char *buf = (char *) emalloc(max_word_size * sizeof(char));

	while (fscanf(fdic, "%s", buf) == 1) {
		if (word_exists[w_get_size(buf)])
			la_new_node(la, w_new(buf), w_get_size(buf));
	}

	free(buf);
	fclose(fdic);
}

void read_pal(FILE *fpal, int max_word_size)
{
	char *word1 = (char *) malloc(max_word_size * sizeof(char));
	char *word2 = (char *) malloc(max_word_size * sizeof(char));

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
