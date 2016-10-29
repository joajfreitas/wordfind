#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "err.h"
#include "word.h"
#include "file.h"


int *find_max_word(FILE *fpal)
{
	char buffer[MAX_WORD_SIZE];
	size_t size=0;
	int index = 1;
	int *index_conv = (int *) ecalloc(MAX_WORD_SIZE,  sizeof(int));

	while (fscanf(fpal, "%s", buffer) == 1) {
		if (isdigit(buffer[0])) continue;
		size = strlen(buffer);
		if (!index_conv[size]) {
			index_conv[size] = index;
			index++;
		}
	}
	return index_conv;
}


void read_dic(FILE *fdic, Lists_Array *la)
{
	/* TODO: tamanho máximo das palavras do dic, perigo buffer*/
	char *buf = (char *) emalloc(MAX_WORD_SIZE * sizeof(char));

	while (fscanf(fdic, "%s", buf) == 1) {
		if (la_get_index(la, w_get_size(buf)))
			la_new_node(la, w_new(buf), w_get_size(buf));
	}

	free(buf);
}

void read_pal(FILE *fpal, int max_word_size)
{
	char *word1 = (char *) emalloc(max_word_size * sizeof(char));
	char *word2 = (char *) emalloc(max_word_size * sizeof(char));

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
}
