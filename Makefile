CFLAGS=-Wall

all: tse ste est

tse: tse.o
	gcc -o tse -Wall tse.o -lm
ste: ste.o
	gcc -o ste -Wall ste.o -lm
est: est.o
	gcc -o est -Wall est.o -lm
clean:
	rm -f *.o tse ste est
