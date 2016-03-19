CC=gcc
CFLAGS=-I.
DEPS = levi.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o levi.o 
	gcc -o levi main.o levi.o -I.
