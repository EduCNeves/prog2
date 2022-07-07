#ifndef __LEITURA__
#define __LEITURA__
     
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 1024

/*typedef struct Log_t {

    int data;

}Log_t;*/

/*
typedef struct Bicicleta_t {
    
    char *nome_bike;
    log_t *informacoes;

}Bicicleta_t;
*/



void ler_arquivo (char* log, char *nome);
void ler_diretorio(char *diretorio, char *nome);
     
#endif

