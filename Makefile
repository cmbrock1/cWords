CFLAGS = -Wall -g
CC = gcc
default: words.o scanner.o shakes.o
	$(CC) $(CFLAGS) -o cWords words.o shakes.o scanner.o
cWords: words.o scanner.o shakes.o
	$(CC) $(CFLAGS) -o cWords minesweeper.o scanner.o
words.o: scanner.h shakes.h words.c
	$(CC) $(CFLAGS) -c words.c
scanner.o: scanner.h scanner.c
	$(CC) $(CFLAGS) -c scanner.c
shakes.o: scanner.h shakes.h
	$(CC) $(CFLAGS) -c shakes.c
clean: 
	$(RM) -f *.o
