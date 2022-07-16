#include "leitura.h"
#include "contas.h"


//ordenação por distancia
void ordenar_por_distancia(Bicicleta_t *bikes, contadores_t *cont){
    int min, i, l, j;
    for ( i = 0; i < cont->cont_bike; i++){
        for ( l = 0; l < bikes[i].cont_log; l++){
            min = l; 
            for (j = l+1; j < bikes[i].cont_log; j++){
                if (bikes[i].informacoes[j].distance < bikes[i].informacoes[min].distance ){
                    min = j;
                }
            }
            troca(bikes,i,min,l);
        }
    } 
}

void troca(Bicicleta_t *bikes, int i, int min, int l){

    log_t aux;

    aux = bikes[i].informacoes[min];
    bikes[i].informacoes[min] = bikes[i].informacoes[l];
    bikes[i].informacoes[l] = aux;


    /*
    aux_data = bikes[i].informacoes[mim].data
    aux_dis = bikes[i].informacoes[mim].distance;
    aux_nome_log = bikes[i].informacoes[mim].nome_log
    aux_hr_max = bikes[i].informacoes[mim].hr_max;
    aux_vel_max = bikes[i].informacoes[mim].vel_max;
    aux_sub_acumulada = bikes[i].informacoes[mim].sub_acumulada;
    aux_tempo = bikes[i].informacoes[mim].tempo

    //bikes[i].informacoes[min].distance  =  bikes[i].informacoes[j].distance;
    
    bikes[i].informacoes[mim].data =  bikes[i].informacoes[l].data;
    bikes[i].informacoes[mim].distance = bikes[i].informacoes[l].distance;
    bikes[i].informacoes[mim].nome_log = bikes[i].informacoes[l].nome_log;
    bikes[i].informacoes[mim].hr_max = bikes[i].informacoes[l].hr_max;
    bikes[i].informacoes[mim].vel_max = bikes[i].informacoes[l].vel_max;
    bikes[i].informacoes[mim].sub_acumulada = bikes[i].informacoes[l].sub_acumulada;
    bikes[i].informacoes[mim].tempo = bikes[i].informacoes[l].tempo;

    //bikes[i].informacoes[j].distance = aux_dis;

    bikes[i].informacoes[l].data =  aux_data;
    bikes[i].informacoes[l].distance = aux_dis;
    bikes[i].informacoes[l].nome_log = aux_nome_log;
    bikes[i].informacoes[l].hr_max = aux_hr_max;
    bikes[i].informacoes[l].vel_max = aux_vel_max;
    bikes[i].informacoes[l].sub_acumulada = aux_sub_aculada;
    bikes[i].informacoes[l].tempo = aux_tempo;*/
    
}

void ordenar_por_data(Bicicleta_t *bikes, contadores_t *cont){
    int min, i, l, j;
    int aux;
    //char *aux1, *aux2, *ano, *mes, *dia;

    for ( i = 0; i < cont->cont_bike; i++){
        for ( l = 0; l < bikes[i].cont_log; l++){
            min = l; 
            for (j = l+1; j < bikes[i].cont_log; j++){

                //pegando a data
                /*aux1 = bikes[i].informacoes[j].data;
                ano = strtok(aux1,"/");
                mes = strtok(NULL,"/");
                dia = strtok(NULL,"/");*/
                aux = strcmp(bikes[i].informacoes[j].data,bikes[i].informacoes[min].data);
                if ( aux == -1  ){
                    min = j;
                }
            }
            troca(bikes,i,min,l);
        }
    } 
}




void ordenar_por_data(Bicicleta_t *bikes, contadores_t *cont){
    int min, i, l, j;
    char *aux1, *aux2, *ano1, *mes1, *dia1, *ano2, *mes2, *dia2;

    for ( i = 0; i < cont->cont_bike; i++){
        for ( l = 0; l < bikes[i].cont_log; l++){
            min = l; 
            for (j = l+1; j < bikes[i].cont_log; j++){
                //pegando a data1
                aux1 = bikes[i].informacoes[j].data;
                ano1 = strtok(aux1,"/");
                mes1= strtok(NULL,"/");
                dia1 = strtok(NULL,"/");

                //pegando a segunda data
                aux2 = bikes[i].informacoes[min].data;
                ano2 = strtok(aux2,"/");
                mes2= strtok(NULL,"/");
                dia2 = strtok(NULL,"/");

                if (strcmp(ano1,ano2) == 0){
                  if (strcmp(mes1,mes2) == 0 ){
                    if (strcmp(dia1,dia2) == -1) {
                      min = j;
                    }
                  }
                  else if (strcmp(mes1,mes2) == -1){
                    min = j;
                  }
                }
                else if (strcmp(ano1,ano2) == -1){
                  min = j;
                }
            }
            troca(bikes,i,min,l);
        }
    } 
}