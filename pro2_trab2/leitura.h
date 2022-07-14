#ifndef __LEITURA__
#define __LEITURA__
     
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 1024

typedef struct Log_t {

    struct dirent **nome_log;
    char data[50];
    // int altitude;
    // int cadence;
    int distance;
    int vel_med;
    int vel_max;
    int hr_med;
    int hr_max;
    int cad_med;
    int subida_acumulada;

}Log_t;


typedef struct Bicicleta_t {
    
    char *nome_bike; //nome de bike
    log_t *informacoes; //vetor de log
    int cont_log; // contos de logs a bike tem

}Bicicleta_t;

typedef struct contadores_t{
    
    int quantidade_log;
    int cont_bike = 0;

}contadores_t;


void ler_arquivo (char* log, char *nome);
void ler_diretorio(char *diretorio, char *nome);
     
#endif
