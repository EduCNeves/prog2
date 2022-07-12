#ifndef __LEITURA__
#define __LEITURA__
     
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 1024

typedef struct Log_t {

    struct dirent **nome_log; //para teste
    int data;

}Log_t;

typedef struct bike{

    struct bike *antes;
    struct bike *prox;

    char *nome_bike;
    log_t *informacoes;
    int cont_log;

} bike;

typedef struct Bicicleta {
    
    struct bike *inicio;
    int quantidade_bike;


}Bicicleta_t;




void ler_arquivo (char* log, char *nome);
void ler_diretorio(char *diretorio, char *nome);
     
#endif

