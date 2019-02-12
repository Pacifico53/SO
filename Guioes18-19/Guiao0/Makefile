CC = gcc
CFLAGS = -Wall

program: program.o person.o

person.o: person.h person.c

program.o: person.h program.c

clean:
	rm -f program *.o
