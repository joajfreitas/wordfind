#include <stdio.h>
#include <stdlib.h>
#include "dict.h"
#include "err.h"


#define MAX_SIZE_WORDS 30

void read_dict(char *filename, Dict *dict);

void usage(char *nomeProg) {
	printf("Uso: %s [ficheiro1.dict] [ficheiro.pal]\n",
				 nomeProg);
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	Dict *dict = NULL;
	if (argc != 3) {
		usage(argv[0]);
	}

	dict = init_dict(MAX_SIZE_WORDS);	
	read_dict(argv[1], dict);
	/*read_pal();
	write_out();*/

	free_dict(dict);
	
	return EXIT_SUCCESS;
}

void read_dict(char *filename, Dict *dict)
{
	FILE *fdict = fopen(filename, "r");

	/*TODO: ler palavras*/
	/*while(fscanf(fdict, "%s", word) == 1){
		write_to_dict(dict, word);
		(*numPalavras)++;
	}*/

	fclose(fdict);


}
