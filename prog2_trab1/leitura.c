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

void checar_nome_bike(Bicicleta_t *bikes, int quantidade_log, char *nome){


  for(int i=0; i < quantidade_log; i++){
    if (strcmp(bike[i]->nome_bike,nome)){
      return i;
    }
  }
  

}



void ler_arquivos (struct dirent **arquivos, Bicicleta_t *bikes, int quantidade_log){

  FILE *arq;
  int i ;
  char *line = malloc (sizeof(char)*LINESIZE);
 
  // abre o arquivo em leitura
  for(i=0; i< quantidade_log; i++ ){
    arq = fopen (arquivos[i]->d_name, "r") ;
    if ( !arq ){
      perror ("Erro ao abrir arquivo TESTE_AQUI") ;
      exit (1) ;
    }

    char pt[50];

    //mostra o cabeçario de cada bicicleta 
    //for (i=0; i<1; i++){
      fgets (line, LINESIZE, arq);
      strtok(line, ":");
      strcpy(pt,strtok(NULL,"\n"));
      checar_nome_bike(bikes, quantidade_log, pt);
      strcpy(,pt);
      /*printf ("%s\n", nome);*/
    //}
    
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