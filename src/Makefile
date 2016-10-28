#CFLAGS=-O3 -pg -Wall -Wextra -pedantic -ansi
#CFLAGS=-g -pg -Wall -Wextra -pedantic -ansi
CFLAGS=-g -Wall -Wextra -pedantic -ansi
#CFLAGS=-Wall -Wextra -pedantic -ansi
CPPFLAGS=-MP -MMD
LDFLAGS=
CC=gcc
SRC=$(wildcard *.c)
EXEC=wordmorph

all:
	make $(EXEC)
	rm -rf *.d

$(EXEC): $(SRC:%.c=%.o)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf *.o
	rm $(EXEC)

-include $(SRC:%.c=%.d)
