#define _DEFAULT_SOURCE
#include "contas.h"



mostrar_bike();
lista_atividades();
lista_data();
lsita_distancia();
lista_acumulada();
histograma();



//ordenação por distancia
ordenar_por_distancia(){
    int min, i, l, j;
    for ( i = 0; i < cont.cont_bike; i++){
        for ( l = 0; l < bikes[i].cont_log; l++){
            min = l; 
            for (j = l+1; j < bikes[i].cont_log; j++){
                if (bikes[i].informacoes[j].distance < bikes[i].informacoes[mim].distance ){
                    min = j;
                }
            }
            troca(bikes,cont,i,min,l);
        }
    } 
}

troca(bikes,cont,i,min,l){

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
    bikes[i].informacoes[l].tempo = aux_tempo;
    
}

void selecao (int vet, int tam){
    int i, j, min, x;
    for (i=1; i<=n-1; i++){
        min = i;
	for (j=i+1; j<=n; j++){
            if (vet[j] < vet[min])
	        min = j;
	}
	x = vet[min];
	vet[min] = vet[i];
	vet[i] = x;
    }
}
