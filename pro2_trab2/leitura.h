#ifndef __LEITURA__
#define __LEITURA__
     
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LINESIZE 1024

typedef struct log_t {

    char nome_log[100];
    char data[100];
    int tempo;
    double distance;
    int hr_max;
    double vel_max;
    double sub_acumulada;
    double vel_med;
    int hr_med;
    int cad;

}log_t;


typedef struct Bicicleta_t {
    
    char *nome_bike; //nome de bike
    log_t *informacoes; //vetor de log
    int cont_log; // contos de logs a bike tem

}Bicicleta_t;

typedef struct contadores_t{
    
    int quantidade_log;
    int cont_bike;

}contadores_t;

typedef struct elev_dado_t{
    int id_bike;
    int id_log;
    double elev;
}elev_dado_t;



void troca(Bicicleta_t *bikes, int i, int min, int l);
void ordenar_por_distancia(Bicicleta_t *bikes, contadores_t *cont);
void ordenar_por_elev(elev_dado_t *elev ,contadores_t *cont);

int imiprir_menu(int fim, Bicicleta_t *bikes, contadores_t *cont);

void mostrar_bike(Bicicleta_t *bikes, contadores_t *cont);
int lista_atividades(Bicicleta_t *bikes, contadores_t *cont, int id_bike);
int lista_data(Bicicleta_t *bikes, contadores_t *cont);
int lista_distancia(Bicicleta_t *bikes, contadores_t *cont);
int lista_acumulada (Bicicleta_t *bikes, contadores_t *cont);
int histograma(Bicicleta_t *bikes, contadores_t *cont,int id_bike);

int checar_nome_bike(Bicicleta_t *bikes, contadores_t *cont, char *nome);
void adicionar_bike(Bicicleta_t *bikes, contadores_t *cont, char *nome, int aux);
void adicionar_log(Bicicleta_t *bikes, int aux, char *arquivo, FILE *arq);

void ler_arquivos (struct dirent **arquivos, Bicicleta_t *bikes, contadores_t *cont);
int filtro (const struct dirent *dir);
     
#endif
