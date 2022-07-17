#define _DEFAULT_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "leitura.h"

#define LINESIZE 1024


void ordenar_por_data(Bicicleta_t *bikes, contadores_t *cont){

    int min, i, l, j,ano1, mes1, dia1, ano2, mes2, dia2;
    char aux1[100], aux2[100];

    for ( i = 0; i < cont->quantidade_log; i++){
        for ( l = 0; l < bikes[i].cont_log; l++){
            min = l; 
            for (j = l+1; j < bikes[i].cont_log; j++){
                //pegando a data1
                strcpy (aux1,bikes[i].informacoes[j].data);
                ano1 = atoi( strtok(aux1,"/") );
                mes1 = atoi ( strtok(NULL,"/") );
                dia1 = atoi ( strtok(NULL,"/") );

                //pegando a segunda data
                strcpy (aux2,bikes[i].informacoes[min].data);
                ano2 = atoi ( strtok(aux2,"/") );
                mes2= atoi ( strtok(NULL,"/") );
                dia2 = atoi ( strtok(NULL,"/") );

                if (ano1 == ano2){
                  if (mes1 == mes2 ){
                    if (dia1 < dia2) {
                      min = j;
                    }
                  }
                  else if (mes1 < mes2){
                    min = j;
                  }
                }
                else if (ano1 < ano2){
                  min = j;
                }
            }
            troca(bikes,i,min,l);
        }
    } 
}

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
    
}

int lista_data(Bicicleta_t *bikes, contadores_t *cont){

  ordenar_por_data(bikes,cont);

  for (int i = 0; i < cont->cont_bike; i++){
    printf("%s\n", bikes[i].nome_bike);
    for (int l = 0; l < bikes[i].cont_log; l++){
      printf("%s ", bikes[i].informacoes[l].nome_log);
      printf ("%s ", bikes[i].informacoes[l].data); 
      printf ("cad(rpm):%d ", bikes[i].informacoes[l].cad);
      printf("hr_med(bpm):%d ",bikes[i].informacoes[l].hr_med);
      printf ("hr_max(bpm):%d ", bikes[i].informacoes[l].hr_max);
      printf("vel_med(km/h):%-5.2lf ", bikes[i].informacoes[l].vel_med);
      printf("vel_max(km/h):%-5.2lf ", bikes[i].informacoes[l].vel_max);
      printf("dist(km):%-5.2lf ",bikes[i].informacoes[l].distance);
      printf ("elev(m):%-5.2lf\n", bikes[i].informacoes[l].sub_acumulada);
    }
    printf("\n");
    ordenar_por_distancia(bikes,cont);
    double dis_medio;
    dis_medio = media_distancia(bikes,cont, i);

    printf("Quandidade de atividades: %d\n", bikes[i].cont_log);
    printf("Total Percorrido em km: %-5.2lf\n", bikes[i].informacoes[bikes[i].cont_log-1].distance);
    printf("Distância Média em km: %-5.2lf\n", dis_medio);
    printf("\n");
  }

  int op;
  printf("\n");
  printf("Digite 1 para voltar no menu ou digite 0 para sair do programa\n");
  scanf("%d", &op);
  return op; 

}

int lista_distancia(Bicicleta_t *bikes, contadores_t *cont){

  ordenar_por_distancia(bikes,cont);

  for (int i = 0; i < cont->cont_bike; i++){
    printf("%s\n", bikes[i].nome_bike);
    for (int l = 0; l < bikes[i].cont_log; l++){
      printf("%s ", bikes[i].informacoes[l].nome_log);
      printf ("%s ", bikes[i].informacoes[l].data); 
      printf ("cad(rpm):%d ", bikes[i].informacoes[l].cad);
      printf("hr_med(bpm):%d ",bikes[i].informacoes[l].hr_med);
      printf ("hr_max(bpm):%d ", bikes[i].informacoes[l].hr_max);
      printf("vel_med(km/h):%-5.2lf ", bikes[i].informacoes[l].vel_med);
      printf("vel_max(km/h):%-5.2lf ", bikes[i].informacoes[l].vel_max);
      printf("dist(km):%-5.2lf ",bikes[i].informacoes[l].distance);
      printf ("elev(m):%-5.2lf\n", bikes[i].informacoes[l].sub_acumulada);
    }
    printf("\n");
    ordenar_por_distancia(bikes,cont);
    double dis_medio;
    dis_medio = media_distancia(bikes,cont, i);

    printf("Quandidade de atividades: %d\n", bikes[i].cont_log);
    printf("Total Percorrido em km: %-5.2lf\n", bikes[i].informacoes[bikes[i].cont_log-1].distance);
    printf("Distância Média em km: %-5.2lf\n", dis_medio);
    printf("\n");
  }

  int op;
  printf("\n");
  printf("Digite 1 para voltar no menu ou digite 0 para sair do programa\n");
  scanf("%d", &op);
  return op;

}

void mostrar_bike(Bicicleta_t *bikes, contadores_t *cont){

  for (int i = 0; i < cont->cont_bike; i++){
    printf("%d. %s\n",i, bikes[i].nome_bike);
  }
  printf("\n");

}

double media_distancia(Bicicleta_t *bikes, contadores_t *cont, int id_bike){
  
  double dis_medio;

  for (int l = 0; l < bikes[id_bike].cont_log; l++){
    dis_medio += bikes[id_bike].informacoes[l].distance;
  }

  return dis_medio/bikes[id_bike].cont_log;

}

int lista_atividades(Bicicleta_t *bikes, contadores_t *cont, int id_bike){

    printf("Bicicleta: %s\n", bikes[id_bike].nome_bike);
    
    for (int l = 0; l < bikes[id_bike].cont_log; l++){
      printf("%d: %s ",l, bikes[id_bike].informacoes[l].nome_log);
      printf ("%s ", bikes[id_bike].informacoes[l].data); 
      printf ("cad(rpm):%d ", bikes[id_bike].informacoes[l].cad);
      printf("hr_med(bpm):%d ",bikes[id_bike].informacoes[l].hr_med);
      printf ("hr_max(bpm):%d ", bikes[id_bike].informacoes[l].hr_max);
      printf("vel_med(km/h):%-5.2lf ", bikes[id_bike].informacoes[l].vel_med);
      printf("vel_max(km/h):%-5.2lf ", bikes[id_bike].informacoes[l].vel_max);
      printf("dist(km):%-5.2lf ",bikes[id_bike].informacoes[l].distance);
      printf ("elev(m):%-5.2lf\n", bikes[id_bike].informacoes[l].sub_acumulada);
    }

  printf("\n");
  ordenar_por_distancia(bikes,cont);
  double dis_medio;
  dis_medio = media_distancia(bikes,cont, id_bike);
  printf("Quandidade de atividades: %d\n", bikes[id_bike].cont_log);
  printf("Total Percorrido em km: %-5.2lf\n", bikes[id_bike].informacoes[bikes[id_bike].cont_log-1].distance);
  printf("Distância Média em km: %-5.2lf\n", dis_medio);

  int op;
  printf("\n");
  printf("Digite 1 para voltar no menu ou digite 0 para sair do programa\n");
  scanf("%d", &op);
  return op;

  
}

int histograma(Bicicleta_t *bikes, contadores_t *cont,int id_bike){

  ordenar_por_distancia(bikes, cont);

  int menor = bikes[id_bike].informacoes[id_bike].distance;
  int maior = bikes[id_bike].informacoes[bikes[id_bike].cont_log-1].distance;


  int piso = (menor / 10);
  int teto = (maior / 10);

  int n = (teto - piso);

  int vetor[n+1];

  for (int i = 0; i < n+1; i++){
    vetor[i] = 0;
  }

  int valor;

  for (int i = 0; i < bikes[id_bike].cont_log; i++){
    valor = bikes[id_bike].informacoes[i].distance;
    valor = valor / 10;
    valor = valor - piso;
    vetor[valor] += 1; 
  }

  printf("%s:\n", bikes[id_bike].nome_bike);

  for (int i = 0; i <= n; i++){
    valor = ((piso+i)*10);
    printf("%d - %d \t|",valor,(valor+9));
    // printf("|");
    for (int j = 0; j < vetor[i]; j++){
      printf("*");
    }
    printf("\n");
  }
  printf("\t\t0123456789#");
  valor = bikes[id_bike].cont_log/10;
  for (int i = 0; i < valor; i++){
    printf("123456789#");
  }
  printf("\n");
  
  printf("Distancia \t| \tQuantidate\n");

  int op;
  printf("\n");
  printf("Digite 1 para voltar no menu ou digite 0 para sair do programa\n");
  scanf("%d", &op);
  return op;

}

void ordenar_por_elev(elev_dado_t *elev ,contadores_t *cont){

  int min, l, j;
  elev_dado_t aux;

  for ( l = 0; l < cont->quantidade_log; l++){
      min = l; 
      for (j = l+1; j < cont->quantidade_log; j++){
          if (elev[j].elev < elev[min].elev ){
              min = j;
          }
      }
      aux = elev[min];
      elev[min] = elev[l];
      elev[l] = aux;
  }
}

int lista_acumulada (Bicicleta_t *bikes, contadores_t *cont){

  elev_dado_t *elev = malloc (sizeof(elev_dado_t)*cont->quantidade_log);
  int cont_e = 0;
  for (int i=0; i<cont->cont_bike; i++){
    for (int l = 0; l < bikes[i].cont_log; l++){
      elev[cont_e].elev = bikes[i].informacoes[l].sub_acumulada;
      elev[cont_e].id_bike = i;
      elev[cont_e].id_log = l;
      cont_e++;
    }
  }

  ordenar_por_elev(elev, cont);

  for (int i = 0; i < cont_e; i++){
    printf("%s ", bikes[elev[i].id_bike].nome_bike);
    printf("%s ", bikes[elev[i].id_bike].informacoes[elev[i].id_log].nome_log);
    printf ("%s ", bikes[elev[i].id_bike].informacoes[elev[i].id_log].data); 
    printf ("cad(rpm):%d ", bikes[elev[i].id_bike].informacoes[elev[i].id_log].cad);
    printf("hr_med(bpm):%d ",bikes[elev[i].id_bike].informacoes[elev[i].id_log].hr_med);
    printf ("hr_max(bpm):%d ", bikes[elev[i].id_bike].informacoes[elev[i].id_log].hr_max);
    printf("vel_med(km/h):%-5.2lf ", bikes[elev[i].id_bike].informacoes[elev[i].id_log].vel_med);
    printf("vel_max(km/h):%-5.2lf ", bikes[elev[i].id_bike].informacoes[elev[i].id_log].vel_max);
    printf("dist(km):%-5.2lf ",bikes[elev[i].id_bike].informacoes[elev[i].id_log].distance);
    printf ("elev(m):%-5.2lf\n", bikes[elev[i].id_bike].informacoes[elev[i].id_log].sub_acumulada); 
  }

  free(elev);
  
  int op;
  printf("\n");
  printf("Digite 1 para voltar no menu ou digite 0 para sair do programa\n");
  scanf("%d", &op);
  return op;
  
}


int imiprir_menu(int fim, Bicicleta_t *bikes, contadores_t *cont){

    printf("0.Digite '0' para sair\n");
    printf("1.Bicicletas Encontradas\n");
    printf("2.Digite a bicicleta para mostrar a lista de atividades\n");
    printf("3.Lista todas atividades agrupadas por bicicleta e ordenadas pela data\n");
    printf("4.Lista todas atividades agrupadas por bicicleta e ordenadas pela distância\n");
    printf("5.Lista todas atividades ordenadas pela subida acumulada\n");
    printf("6.Histograma\n");

    int op,i;
    printf("qual opção você quer escolher?\n");
    scanf("%d", &op);

    switch ( op ){
        case 1:
            system("clear");
            printf("Listas de bicicletas:\n");
            mostrar_bike(bikes, cont);
            printf("Digite 1 para voltar no menu ou digite 0 para sair do programa\n");
            scanf("%d", &fim);
            system("clear");
            break;
        case 2:
            system("clear");
            mostrar_bike(bikes, cont);
            printf("Qual bicicleta você quer ver a atividade, digite o numero dela:\n");
            scanf("%d",&i);
            system("clear");
            fim = lista_atividades(bikes, cont, i);
            system("clear");
            break;
        case 3:
            system("clear");
            fim = lista_data(bikes, cont);
            system("clear");
            break;
        case 4:
            system("clear");
            fim = lista_distancia(bikes, cont);
            system("clear");
            break;
        case 5:
            system("clear");
            fim = lista_acumulada(bikes,cont);
            system("clear");
            break;
        case 6:
            system("clear");
            mostrar_bike(bikes, cont);
            printf("Qual bicicleta você quer ver o histograma, digite o numero dela:\n");
            scanf("%d",&i);
            system("clear");
            fim = histograma(bikes,cont,i);
            system("clear");
            break;
        case 0:
            system("clear");
            fim = 0;
            break;
      }
    return fim;

}

int flag = 1;

void adicionar_log(Bicicleta_t *bikes, int aux, char *arquivo, FILE *arq, contadores_t *cont){

  strcpy(bikes[aux].informacoes[bikes[aux].cont_log].nome_log,arquivo);

  char *line = malloc (sizeof(char)*LINESIZE);
  int cad_velha,cad_medio,cad,hr_velho,hr_medio, segundos,horas, minutos, hr,segundo_velho, segundos_atual, dif_segundo;;
  char *pt, *ano, *mes, *dia, *tempo, *h, *m, *s;
  double distance,vel,alt_novo,alt_velho, vel_medio, vel_velho;

  fgets (line, LINESIZE, arq);
  while (! feof (arq)){
    
    pt = strtok(line, ": ");

    if (!strcmp(pt,"timestamp")){
      
      pt = strtok(NULL," ");
      tempo = strtok(NULL," ");
      
      //pegando a data
      ano = strtok(pt,"-");
      mes = strtok(NULL,"-");
      dia = strtok(NULL,"-");
      strcpy(bikes[aux].informacoes[bikes[aux].cont_log].data,ano);
      strcat(bikes[aux].informacoes[bikes[aux].cont_log].data,"/");
      strcat(bikes[aux].informacoes[bikes[aux].cont_log].data,mes);
      strcat(bikes[aux].informacoes[bikes[aux].cont_log].data,"/");
      strcat(bikes[aux].informacoes[bikes[aux].cont_log].data,dia);
      
      //pegando o tempo
      h = strtok(tempo,":");
      horas = atoi(h);
      horas = horas*3600;
      m = strtok(NULL,":");
      minutos = atoi(m);
      minutos = minutos*60;
      s = strtok(NULL,":");
      segundos = atoi(s); 
      segundos = horas+minutos+segundos;

      segundo_velho = bikes[aux].informacoes[bikes[aux].cont_log].tempo;
      segundos_atual = segundos;
      bikes[aux].informacoes[bikes[aux].cont_log].tempo = segundos;

      dif_segundo = segundos_atual - segundo_velho;


      //velocidade media
      vel_medio += vel_velho * dif_segundo;
      if (vel_velho != 0){
        cont->cont_segundos_vel += dif_segundo; 
      }

      //cadencia medio
      cad_medio += cad_velha * dif_segundo;
      if (cad_velha != 0 ){
        cont->cont_segundos_cad += dif_segundo;
      }

      //hr medio
      hr_medio += hr_velho * dif_segundo;
      if (hr_velho != 0 ){
        cont->cont_segundos_hr +=  dif_segundo;
      }

    }

    if (!strcmp(pt,"distance")){
      pt = strtok(NULL," ");
      distance = atof(pt);
      bikes[aux].informacoes[bikes[aux].cont_log].distance = distance/1000;
    }

    if (!strcmp(pt,"heart_rate")){
      pt = strtok(NULL," ");

      if (flag == 1){
        hr = atof(pt);
        hr_velho = hr;
        flag = 0;
      }
      else {
        hr = atoi(pt);
      }

      if (bikes[aux].informacoes[bikes[aux].cont_log].hr_max < hr){
          bikes[aux].informacoes[bikes[aux].cont_log].hr_max = hr;
      }

      hr_velho = hr;
    }

    if (!strcmp(pt,"speed")){
      pt = strtok(NULL," ");
      
      if (flag == 1){
        vel = atof(pt);
        vel_velho = vel;
        flag = 0;
      }
      else {
        vel = atof(pt);
      }

      vel = vel*3.6;
      if (bikes[aux].informacoes[bikes[aux].cont_log].vel_max < vel){
          bikes[aux].informacoes[bikes[aux].cont_log].vel_max = vel;
      }

      vel_velho = vel;

    }

    if (!strcmp(pt,"altitude")){
      pt = strtok(NULL," ");
      if (flag == 1){
        alt_novo = atof(pt);
        alt_velho = alt_novo;
        flag = 0;
      }
      else{
        alt_novo = atof(pt);
      }  
      if (alt_novo > alt_velho && alt_velho > 0){
        bikes[aux].informacoes[bikes[aux].cont_log].sub_acumulada += alt_novo - alt_velho;
      }
      alt_velho = alt_novo;
    }
    
    if (!strcmp(pt,"cadence")){
      pt = strtok(NULL," ");
      
      if (flag == 1){
        cad = atof(pt);
        cad_velha = cad;
        flag = 0;
      }
      else {
        cad = atof(pt);
      }

      cad_velha = cad;

    }

    fgets (line, LINESIZE, arq); //lebo a próxima linha
    //flag = 0;
  }

  bikes[aux].informacoes[bikes[aux].cont_log].vel_med = vel_medio/cont->cont_segundos_vel;
  bikes[aux].informacoes[bikes[aux].cont_log].hr_med = hr_medio/cont->cont_segundos_hr;
  bikes[aux].informacoes[bikes[aux].cont_log].cad = cad_medio/cont->cont_segundos_cad;


  bikes[aux].cont_log++;

  free(line);

}

void adicionar_bike(Bicicleta_t *bikes, contadores_t *cont, char *nome, int aux){

  strcpy(bikes[aux].nome_bike,nome);
  cont->cont_bike++;

}

int checar_nome_bike(Bicicleta_t *bikes, contadores_t *cont, char *nome){

  int i;
  if (cont->cont_bike == 0){//ver se esta vazio
    return 1;
  }
  else {
    for (i = 0; i < cont->cont_bike; i++){
      if (!strcmp(bikes[i].nome_bike,nome)){ //existe um igual
        return i;
      }
    }   
  }
  return i+1;

}


void ler_arquivos (struct dirent **arquivos, Bicicleta_t *bikes, contadores_t *cont){

  FILE *arq;
  int i,aux = 0;
  char *line = malloc (sizeof(char)*LINESIZE);
 
  // abre o arquivo em leitura
  for(i=0; i < cont->quantidade_log; i++ ){
    
    arq = fopen (arquivos[i]->d_name, "r") ;
    if ( !arq ){
      perror ("Erro ao abrir arquivo") ;
      exit (1) ;
    }

    char pt[cont->quantidade_log];

    fgets (line, LINESIZE, arq);
    strtok(line, ":");
    strcpy(pt,strtok(NULL,"\n"));
    aux = checar_nome_bike(bikes, cont, pt);
    if ( aux > cont->cont_bike){
      adicionar_bike(bikes,cont,pt,aux-1);
      adicionar_log(bikes,aux-1,arquivos[i]->d_name, arq,cont);  
    }
    else {
      adicionar_log(bikes,aux,arquivos[i]->d_name, arq,cont);
    }
      
    // fecha o arquivo
    fclose (arq) ;

  }

  free(line);
 
}

//filtro para aquivos .log
int filtro (const struct dirent *dir){

  int size = strlen(dir->d_name);

  // se o tamanho for invalido ou nao for um arquivo
  if ( size < 1 || dir->d_type != DT_REG )
    return 0;
  
  // se tiver .ppm no final do arquivo
  if ( dir->d_name[size - 4] == '.' && dir->d_name[size - 3] == 'l'
    && dir->d_name[size - 2] == 'o' && dir->d_name[size - 1] == 'g' ){
    return 1;
  }

  return 0;
}

