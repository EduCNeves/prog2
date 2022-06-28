#include "leitura.h"

int main(int argc, char **argv){

  char *diretorio = malloc (sizeof(char)*64);
  strcpy(diretorio, "./");

  if (strcmp(argv[1],"-d") == 0)
    strcat(diretorio,argv[2]);

  printf("%s\n", diretorio);
  ler_diretorio(diretorio);

  return 0;
}