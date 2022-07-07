#define _DEFAULT_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include "leitura.h"

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

void inserir_



void ler_arquivo (char* log, char *nome){

  FILE *arq ;
  int i ;
  char *line = malloc (sizeof(char)*LINESIZE);
 
  // abre o arquivo em leitura
  arq = fopen (log, "r") ;
  if ( !arq ){
    perror ("Erro ao abrir arquivo TESTE_AQUI") ;
    exit (1) ;
  }

  char pt[50];

  //mostra o cabeçario de cada bicicleta 
  for (i=0; i<1; i++){
    fgets (line, LINESIZE, arq);
    strtok(line, ":");
    strcpy(pt,strtok(NULL,"\n"));
    strcpy(nome,pt);
    /*printf ("%s\n", nome);*/
  }
 
  // fecha o arquivo
  fclose (arq) ;
}

void ler_diretorio(char *diretorio, char *nome){

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
        ler_arquivo(arquivo, nome);
    }
  }
 
   // fecha o diretório
   (void) closedir (dirstream);

}
