CC=gcc
CFLAGS=-g -Wall -ansi -pedantic

wordmorph: main.o list.o dict.o err.o 
	$(CC) $(CFLAGS) -o wordmorph  main.o list.o dict.o err.o
	rm -f *.o  a.out *~

main.o: main.c err.h dict.h
	$(CC) -c $(CFLAGS) main.c

list.o: list.c list.h err.h
	$(CC) -c $(CFLAGS) list.c

dict.o: dict.c dict.h err.h list.h
	$(CC) -c $(CFLAGS) dict.c

err.o: err.c err.h
	$(CC) -c $(CFLAGS) err.c

clean::
	rm -f *.o core a.out *~



