CC=gcc
CFLAGS=-g -Wall -ansi -pedantic

wordmorph: main.o list.o lists_array.o err.o 
	$(CC) $(CFLAGS) -o wordmorph  main.o list.o lists_array.o err.o
	rm -f *.o  a.out *~

main.o: main.c err.h lists_array.h
	$(CC) -c $(CFLAGS) main.c

list.o: list.c list.h err.h
	$(CC) -c $(CFLAGS) list.c

lists_array.o: lists_array.c lists_array.h err.h list.h
	$(CC) -c $(CFLAGS) lists_array.c

err.o: err.c err.h
	$(CC) -c $(CFLAGS) err.c

clean::
	rm -f *.o core a.out *~



