#define _DEFAULT_SOURCE
#include "leitura.h"

int main(int argc, char **argv){

  contadores_t cont;
  cont.cont_bike = 0;
  cont.quantidade_log = 0;


  //int quantidade_log = 0;
  char d_home[LINESIZE];
  struct dirent **nome_log;
  //int cont_bike = 0;

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
    fprintf("Erro quantidade_log");
    return 1;
  }

  //alocando vetor de bikes
  Bicicleta_t *bikes = malloc(sizeof(Bicicleta_t)*cont.quantidade_log);
  for (int i; i<cont.quantidade_log; i++){
    bikes[i].nome_bike = malloc (sizeof(char)*LINESIZE);
    bikes[i].informacoes = malloc (sizeof(log_t)*cont.quantidade_log);
    bikes[i].cont_data = 0;
  }


  //leitura de arquivos
  ler_arquivos(nome_log, bikes, cont);

  while (imiprir_menu()){
    
  }
  

  // Bicicleta_t bike;
  // alocacao_vetor(&bike);
  // ler_diretorio(diretorio, bikes, &quantidade_log);
  // for (int 
  //   i=0; i<1; i++){
  //   printf ("%s\n", nome);
  // }

  return 0;
}