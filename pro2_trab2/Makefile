CFLAGS = -Wall -g

all: main

main: main.o leitura.o
	gcc -std=c99 main.o leitura.o -o gps

leitura.o: leitura.c leitura.h
	gcc -c  -std=c99 leitura.c $(CFLAGS)

main.o : main.c 
	gcc -c -std=c99 main.c  $(CFLAGS)

clean:
	rm -rf ./*.o
	 
purge: clean
	rm -rf main