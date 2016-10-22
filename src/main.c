#include <stdio.h>
#include <stdlib.h>
#include "const.h"
#include "lists_array.h"
#include "err.h"

void usage(char *nomeProg) {
	printf("Uso: %s [dicionário.dic] [problemas.pal]\n", nomeProg);
	exit(EXIT_FAILURE);
}

void read_dic(char *filename, Lists_Array *la)
{
	FILE *fdic = efopen(filename, "r");
	char word[MAX_WORD_SIZE];

	while (fscanf(fdic, "%s", word) == 1) {
		la_write(la, word);
	}

	fclose(fdic);
}

void free_item(void *this)
{
	free(this);
}

int main(int argc, char *argv[])
{
	Lists_Array *la;
	if (argc != 3) {
		usage(argv[0]);
	}

	la = la_init(MAX_WORD_SIZE);
	read_dic(argv[1], la);

	/*
	read_pal();
	write_out();
	*/

	la_free(la, &free_item);

	return EXIT_SUCCESS;
}
