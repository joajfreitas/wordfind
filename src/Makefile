CC=gcc
CFLAGS=-O3 -Wall -ansi -pedantic -Wextra -Wunused-result

wordmorph: main.o err.o list.o lists_array.o file.o word.o
	$(CC) $(CFLAGS) -o wordmorph main.o err.o list.o lists_array.o file.o word.o
	rm -f *.o  a.out *~

main.o: main.c err.h const.h file.h word.h
	$(CC) -c $(CFLAGS) main.c

err.o: err.c err.h
	$(CC) -c $(CFLAGS) err.c

file.o: file.c file.h err.h const.h word.h
	$(CC) -c $(CFLAGS) file.c

list.o: list.c list.h const.h err.h word.h
	$(CC) -c $(CFLAGS) list.c

lists_array.o: lists_array.c lists_array.h err.h const.h list.h
	$(CC) -c $(CFLAGS) lists_array.c

word.o: word.c word.h err.h
	$(CC) -c $(CFLAGS) word.c

clean::
	rm -f *.o core a.out *~ wordmorph
