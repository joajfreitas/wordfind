#include <stdio.h>
#include <stdlib.h>
#include "const.h"
#include "lists_array.h"
#include "err.h"

void usage(char *nomeProg) {
	printf("Uso: %s [ficheiro1.dict] [ficheiro.pal]\n", nomeProg);
	exit(EXIT_FAILURE);
}

void read_dict(char *filename, Lists_Array *l)
{
	FILE *fdict = fopen(filename, "r");

	/* TODO: ler palavras
	while(fscanf(fdict, "%s", word) == 1){
		write_to_dict(dict, word);
		(*numPalavras)++;
	}*/

	fclose(fdict);
}

void free_item(void *this)
{
	return;
}

int main(int argc, char *argv[])
{
	Lists_Array *l = NULL;
	if (argc != 3) {
		usage(argv[0]);
	}

	l = init_lists_array(MAX_WORD_SIZE);
	read_dict(argv[1], l);
	/*
	read_pal();
	write_out();
	*/

	free_lists_array(l, &free_item);

	return EXIT_SUCCESS;
}
