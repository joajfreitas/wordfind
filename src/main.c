#include <stdio.h>
#include <stdlib.h>
#include "const.h"
#include "lists_array.h"
#include "err.h"

void usage(char *nomeProg) {
	printf("Uso: %s [ficheiro1.dict] [ficheiro.pal]\n", nomeProg);
	exit(EXIT_FAILURE);
}

void read_fdict(char *filename, Lists_Array *l)
{
	FILE *fdict = efopen(filename, "r");
	char word[MAX_WORD_SIZE];
	
	while(fscanf(fdict, "%s", word) == 1){
		la_write(l, word);
	}

	fclose(fdict);
}

void free_item(void *this)
{
	free(this);
}

int main(int argc, char *argv[])
{
	Lists_Array *l = NULL;
	if (argc != 3) {
		usage(argv[0]);
	}

	l = la_init(MAX_WORD_SIZE);
	read_fdict(argv[1], l);

	/*
	read_pal();
	write_out();
	*/

	la_free(l, &free_item);

	return EXIT_SUCCESS;
}
