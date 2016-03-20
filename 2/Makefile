IDIR =./include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=./src
LDIR =./lib

LIBS=-lm

_DEPS = levi.h durfee.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o levi.o durfee.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	gcc -g -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
