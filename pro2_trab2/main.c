#define _DEFAULT_SOURCE
#include "leitura.h"

int main(int argc, char **argv){

  contadores_t cont;
  cont.cont_bike = 0;
  cont.quantidade_log = 0;
  cont.cont_segundos_cad = 1;
  cont.cont_segundos_vel = 1;
  cont.cont_segundos_hr = 1;


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
      bikes[i].informacoes[l].vel_med = 0;
      bikes[i].informacoes[l].cad = 0;
      bikes[i].informacoes[l].hr_med = 0;
      bikes[i].informacoes[l].sub_acumulada = 0;
    }
  }

  //leitura de arquivos
  printf("Lendo os arquivos ...\n");
  ler_arquivos(nome_log, bikes, &cont);
  system("clear");

  int fim = 1;
  while (fim != 0){
    //system("clear");
    fim = imiprir_menu(fim, bikes, &cont);
  }
  printf("Obrigado por ter usado o programa\n");
  
  free(diretorio);
  for (int i=0; i<cont.quantidade_log; i++){
    free(bikes[i].nome_bike);
    free(bikes[i].informacoes);
  }
  free(bikes);

  return 0;
}