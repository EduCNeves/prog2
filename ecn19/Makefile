CFLAGS = -Wall -g
LIBS = -lm

all: pgmlbp pgmlimiar pgmmedia pgmmediana pgmnega pgmrotacao 

pgmlbp: pgmlbp.o imagem.o
	gcc pgmlbp.o imagem.o -o pgmlbp $(LIBS)

pgmmediana: pgmmediana.o imagem.o
	gcc pgmmediana.o imagem.o -o pgmmediana $(LIBS)

pgmmedia: pgmmedia.o imagem.o
	gcc pgmmedia.o imagem.o -o pgmmedia $(LIBS)

pgmlimiar: pgmlimiar.o imagem.o
	gcc pgmlimiar.o imagem.o -o pgmlimiar $(LIBS)

pgmrotacao: pgmrotacao.o imagem.o
	gcc pgmrotacao.o imagem.o -o pgmrotacao $(LIBS)

pgmnega: pgmnega.o imagem.o
	gcc pgmnega.o imagem.o -o pgmnega $(LIBS)
        
imagem.o: imagem.c imagem.h
	gcc -c imagem.c $(CFLAGS)

pgmmediana.o : pgmmediana.c 
	gcc -c pgmmediana.c  $(CFLAGS)

pgmlbp.o : pgmlbp.c 
	gcc -c pgmlbp.c  $(CFLAGS)

pgmmedia.o : pgmmedia.c 
	gcc -c pgmmedia.c  $(CFLAGS)

pgmlimiar.o : pgmlimiar.c 
	gcc -c pgmlimiar.c  $(CFLAGS)

pgmrotacao.o : pgmrotacao.c 
	gcc -c pgmrotacao.c  $(CFLAGS)

pgmnega.o : pgmnega.c 
	gcc -c pgmnega.c  $(CFLAGS)

clean:
	rm -rf ./*.o
	 
purge: clean
	rm -rf pgmlbp pgmlimiar pgmmedia pgmmediana pgmnega pgmrotacao