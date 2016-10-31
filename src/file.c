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

void read_pal(FILE *fpal, Lists_Array *la)
{
	char *word1 = (char *) emalloc(MAX_WORD_SIZE * sizeof(char));
	char *word2 = (char *) emalloc(MAX_WORD_SIZE * sizeof(char));

	int challenge;

	FILE *fstat = NULL;

	fstat = efopen("dummy.stat", "w");

	/* Verificar apenas por um novo problema (um por linha);
	 * assume-se que o ficheiro está formatado corretamente,
	 * por isso não se verificam os fscanf() dentro do ciclo. */
	while (fscanf(fpal, "%s", word1) == 1) {
		fscanf(fpal, "%s", word2);
		fscanf(fpal, "%d", &challenge);
		/* TODO: ou guardar os problemas ou resolver um por um */

		if (challenge == 1) {
			fprintf(fstat, "%s %d\n", word1, la_get_sizes(la)[la_get_ajusted_index(la, strlen(word1))]);
		}
		else if (challenge == 2) {
			fprintf(fstat, "%s %d\n", word1, la_binary_search(la, word1));
			fprintf(fstat, "%s %d\n", word2, la_binary_search(la, word2));

		}
		else
			continue;

		fprintf(fstat, "\n");
	}

	fclose(fstat);
	free(word1);
	free(word2);
}
