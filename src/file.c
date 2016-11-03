#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "err.h"
#include "const.h"
#include "word.h"
#include "file.h"


int *find_word_sizes(FILE *fpal)
{
	char buffer[MAX_WORD_SIZE];
	size_t size = 0;
	int i = 1;
	int *word_sizes = (int *) ecalloc(MAX_WORD_SIZE, sizeof(int));

	while (fscanf(fpal, "%s", buffer) == 1) {
		if (isdigit(buffer[0])) continue;

		size = strlen(buffer);
		if (!word_sizes[size]) {
			word_sizes[size] = i++;
		}
	}

	return word_sizes;
}


void read_dic(FILE *fdic, Lists_Array *la)
{
	char *buf = (char *) emalloc(MAX_WORD_SIZE * sizeof(char));

	while (fscanf(fdic, "%s", buf) == 1) {
		if (la_get_index(la, w_get_size(buf)))
			la_new_node(la, w_new(buf), w_get_size(buf));
	}

	free(buf);
}

void solve_pal(FILE *fpal, Lists_Array *la)
{
	char *word1 = (char *) emalloc(MAX_WORD_SIZE * sizeof(char));
	char *word2 = (char *) emalloc(MAX_WORD_SIZE * sizeof(char));

	int challenge;

	FILE *fstat = NULL;

	/* TODO: out filename */
	fstat = efopen("dummy.stat", "w");

	/* Verificar apenas por um novo problema (um por linha);
	 * assume-se que o ficheiro está formatado corretamente,
	 * por isso não se verificam os fscanf() dentro do ciclo. */
	while (fscanf(fpal, "%s", word1) == 1) {
		fscanf(fpal, "%s", word2);
		fscanf(fpal, "%d", &challenge);

		if (challenge == 1) {
			fprintf(fstat, "%s %d\n", word1, la_get_sizes(la)[la_get_adjusted_index(la, strlen(word1))]);
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
