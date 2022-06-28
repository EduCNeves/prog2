CFLAGS = -Wall -g
LIBS = -lm

all: main

main: main.o leitura.o
	gcc main.o leitura.o -o main $(LIBS)

leitura.o: leitura.c leitura.h
	gcc -c leitura.c $(CFLAGS)

main.o : main.c 
	gcc -c main.c  $(CFLAGS)

clean:
	rm -rf ./*.o
	 
purge: clean
	rm -rf main