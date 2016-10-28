#CFLAGS=-O3 -Wall -Wextra -pedantic -ansi
#CFLAGS=-Wall -Wextra -pedantic -ansi
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
	rm -rf *.o *.out*
	rm -rf $(EXEC)

-include $(SRC:%.c=%.d)

# TODO: criar make test, automatizar memcheck, massif e gprof
