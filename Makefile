CFLAGS=-Wall

all: tse ste

tse: tse.o
	gcc -o tse -Wall tse.o -lm
ste: ste.o
	gcc -o ste -Wall ste.o -lm -lrt
clean:
	rm -f *.o tse ste
