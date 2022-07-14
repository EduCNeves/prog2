#define _DEFAULT_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "leitura.h"
#include "contas.h"

#define LINESIZE 1024

/*
void ler_todo_arquivo(){
  
  // lê TODAS as linhas do arquivo
  int i = 1;
  fgets (line, max, arq) ;     // tenta ler uma linha
  while (! feof (arq)){              // testa depois de tentar ler!
    printf ("%s", line) ;
    fgets (line, max, arq) ;   // tenta ler a próxima linha
    i++ ;
  }
}*/


/*
//alocando a vetor
void alocacao_vetor(Bicicleta_t *bike){
  //alocando a vetor
  bike->nome = malloc (sizeof(char)*LINESIZE);
  
  
  //zerando a matriz
  for (i=0; i < orig->altura; i++)
      orig->img[i][j] = 0;  
}*/

/*
int imiprir_menu(){

    printf("0.Digite '0' para sair");
    printf("1.Bicicletas Encontradas");
    printf("2.Digite a bicibleta para mostrar a lsita de atividades");
    printf("3.Lista todas atividades agrupadas por bicicleta e ordenadas pela data");
    printf("4.Lista todas atividades agrupadas por bicicleta e ordenadas pela distância");
    printf("5.Lista todas atividades ordenadas pela subida acumulada");
    printf("6.Histograma");

    int op;
    scanf("%d", &op);

    switch ( op ){
        case 1:
            mostrar_bike();
            break;
        case 2:
            lista_atividades();
            break;
        case 3:
            lista_data();
            break;
        case 4:
            lsita_distancia();
            break;
        case 5:
            lista_acumulada();
            break;
        case 6:
            histograma();
            break;
        case 0:
            printf("Obrigado por ter usado o programa");
            return 0;
            break;
    }
    

}*/

void adicionar_log(Bicicleta_t *bikes, int aux, char *arquivo){

  strcpy(bikes[aux].informacoes[bikes[aux].cont_log].nome_log,arquivo);
  bikes[aux].cont_log++;

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
        adicionar_log(bikes,aux-1,arquivos[i]->d_name);  
      }
      else {
        adicionar_log(bikes,aux,arquivos[i]->d_name);
      }
      
      /*
      fgets (line, LINESIZE, arq);
      strtok(line, ":");
      strcpy(bikes->informacoes->data,strtok(NULL,","));//arrumar a data

      //altitude
      fgets (line, LINESIZE, arq);
      pt = strtok(line, ":");
      if(!strcmp(pt,"altitude")){
        pt = strtok(NULL,":")
        sscanf(, "%lf", &bike->subida_acumulada);
        strcpy(,strtok(NULL,"m"));
      }*/

    
    // fecha o arquivo
    fclose (arq) ;

  }


 
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

/*char ler_diretorio(char *diretorio, Bicicleta_t *bikes){
  // pega o diretorio inicial em que o programa esta rodando
  getcwd(home_directory, sizeof(home_directory));
  // muda o diretorio de executacao do programa e checa retorno
  ret = chdir(tiles_directory);
  if ( ret != 0 ){
    fprintf(stderr, "Not able to change directory %s\n", tiles_directory);
    exit(EXIT_FAILURE);
  }
  DIR *dirstream;
  struct dirent *direntry;
  char *arquivo = malloc (sizeof(char)*LINESIZE);
 
  // abre um diretório
  dirstream = opendir (diretorio);
  if ( ! dirstream ){
    perror ("Erro de abrir diretorio");
    exit (1);
  }
 
  // varre as entradas do diretório aberto
  for (;;){
    // pega a próxima entrada
    direntry = readdir (dirstream);
 
    // se for nula, encerra a varredura
    if (! direntry)
      break ;
 
    // mostra conteúdo da entrada
    if (direntry->d_type == DT_REG){
        strcat(strcpy(arquivo, diretorio), "/");
        strcat(arquivo, direntry->d_name);
        //ler_arquivo(arquivo, bikes);
    }
  }
 
   // fecha o diretório
   (void) closedir (dirstream);
   return arquivo;
}
*/