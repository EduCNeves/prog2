#ifndef __LEITURA__
#define __LEITURA__
     
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

/*
typedef struct Bicicleta_t {
    
    char nome;  

}Bicicleta_t;*/


void ler_arquivo (char* log);
void ler_diretorio(char *diretorio);
     
#endif

