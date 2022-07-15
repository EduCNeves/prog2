#define _DEFAULT_SOURCE
#include "leitura.h"

int main(int argc, char **argv){

  contadores_t cont;
  cont.cont_bike = 0;
  cont.quantidade_log = 0;


  char d_home[LINESIZE];
  struct dirent **nome_log;

  char *diretorio = malloc (sizeof(char)*64);
  strcpy(diretorio, "./");

  if (strcmp(argv[1],"-d") == 0)
    strcat(diretorio,argv[2]);

  getcwd(d_home, sizeof(d_home));


  int ret = chdir(diretorio);
  if ( ret != 0 ){
    fprintf(stderr, "Não foi possivel acessar  o diretorio %s\n", diretorio);
    exit(EXIT_FAILURE);
  }

  //contando quantos logs tem no diretorio de log
  cont.quantidade_log = scandir(".", &nome_log, filtro, alphasort);

  if (cont.quantidade_log <= 0){
    fprintf(stderr, "Erro quantidade_log");
    return 1;
  }

  //alocando vetor de bikes
  Bicicleta_t *bikes = malloc(sizeof(Bicicleta_t)*cont.quantidade_log);

  for (int i=0; i<cont.quantidade_log; i++){
    bikes[i].nome_bike = malloc (sizeof(char)*LINESIZE);
    //printf("%p\n", bikes[i].nome_bike);
    bikes[i].informacoes = malloc (sizeof(log_t)*cont.quantidade_log);
    bikes[i].cont_log = 0;
    for (int l = 0; l < cont.quantidade_log; l++){
      bikes[i].informacoes[l].tempo = 0;
      bikes[i].informacoes[l].distance = 0;
      bikes[i].informacoes[l].hr_max = 0;
      bikes[i].informacoes[l].vel_max = 0;
    }
  }

  //leitura de arquivos
  ler_arquivos(nome_log, bikes, &cont);
  //for (int i = 0; i < cont.cont_bike; i++){
    printf("%s\n", bikes[0].nome_bike);
    printf(" quantidades de logs:%d\n", bikes[0].cont_log);
    for (int l = 0; l < bikes[0].cont_log; l++){
      printf("%s  ", bikes[0].informacoes[l].nome_log);
      printf ("data:%s   ", bikes[0].informacoes[l].data); 
      printf("dist:  %-5.2lf   ",bikes[0].informacoes[l].distance);
      printf ("HR_MAX: %d   ", bikes[0].informacoes[l].hr_max);
      printf ("VEL_MAX: %-5.2lf   ", bikes[0].informacoes[l].vel_max);
      printf ("ELE: %-5.2lf\n", bikes[0].informacoes[l].sub_acumulada);
      printf ("tempo: %d\n", bikes[0].informacoes[l].tempo);
    }
    
  //}
  printf("\n");
  printf(" total de arquivos:%d\n", cont.quantidade_log);
  printf(" total de bikes:%d\n", cont.cont_bike);
  
  return 0;
}