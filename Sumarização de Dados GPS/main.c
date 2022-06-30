#define _DEFAULT_SOURCE
#include "leitura.h"

int main(int argc, char **argv){

  char *diretorio = malloc (sizeof(char)*64);
  strcpy(diretorio, "./");

  if (strcmp(argv[1],"-d") == 0)
    strcat(diretorio,argv[2]);

  ler_diretorio(diretorio);

  return 0;
}
