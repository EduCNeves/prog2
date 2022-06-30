#define _DEFAULT_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include "leitura.h"

#define MAX 64

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

void ler_arquivo (char* log){

  FILE *arq ;
  int i ;
  char *line = malloc (sizeof(char)*MAX);
 
  // abre o arquivo em leitura
  arq = fopen (log, "r") ;
  if ( !arq ){
    perror ("Erro ao abrir arquivo TESTE_AQUI") ;
    exit (1) ;
  }

  
  //mostra o cabeçario de cada bicicleta 
  for (i=0; i<3; i++){
    fgets (line, MAX, arq);
    printf ("%s", line);
  }
 
  // fecha o arquivo
  fclose (arq) ;
}

void ler_diretorio(char *diretorio){

  DIR *dirstream;
  struct dirent *direntry;
  char *arquivo = malloc (sizeof(char)*MAX);
 
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
        ler_arquivo(arquivo);
    }
  }
 
   // fecha o diretório
   (void) closedir (dirstream);

}
