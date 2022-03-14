#ifndef __IMAGEM__
#define __IMAGEM__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100

typedef struct Imagem_t {

    unsigned char **img;
    char tipo[2];
    int altura;
    int coluna;
    int max;  

}Imagem_t;


void alocacao_matriz(Imagem_t *orig);
void ler_imagem(Imagem_t *orig, FILE *arq);
void imprimir_imagem(Imagem_t *orig, FILE *arqs);
#endif