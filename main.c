#define _DEFAULT_SOURCE
#include "leitura.h"

int main(int argc, char **argv){


  char *diretorio = malloc (sizeof(char)*64);
  strcpy(diretorio, "./");

  if (strcmp(argv[1],"-d") == 0)
    strcat(diretorio,argv[2]);

  /*Bicicleta_t bike;
  alocacao_vetor(&bike);*/

  char *nome = malloc (sizeof(char)*LINESIZE);

  ler_diretorio(diretorio, nome);

  for (int i=0; i<1; i++){
    printf ("%s\n", nome);
  }

  return 0;
}