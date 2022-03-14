#include "imagem.h"

void media(Imagem_t *orig, Imagem_t *novo){

    //copiando os argumemos do origunal e colocando no novo
    strcpy(novo->tipo, orig->tipo);
    novo->altura = orig->altura;
    novo->coluna = orig->coluna;
    novo->max = orig->max;

    //alocação da nova matriz
    alocacao_matriz(novo);

    int aux_l, aux_c;
    int soma = 0;
    int num = 0;

    //fazendo o algoritmo do filtro media
    for (int i = 0; i < orig->altura; i++){
        for (int j = 0; j < orig->coluna; j++){
            aux_l = i;
            aux_c = j;
            for (int k = aux_l-1; k <= aux_l+1 ; k++){
                for (int l = aux_c-1; l <= aux_c+1; l++){
                    if ( k >= 0 && l >=0 && k < orig->altura && l < orig->coluna ){
                        //fazendo a soma
                        soma = orig->img[k][l] + soma;
                        num++;
                    }
                }
            }
            //fazendo a media com a soma
            novo->img[i][j] = soma/num;
            num = 0;
            soma = 0;
        }
    }
}



int main(int argc, char **argv){

    FILE *arq;
    FILE *arqs;
    char input[MAX] , output[MAX];
    Imagem_t orig, novo;

    //lendo a linha de comando
    for (int i = 0; i < argc; i++){
        if (argv[i][0] == '-'){
            if (argv[i][1] == 'i')
                strcpy(input, argv[i+1]);
            else if (argv[i][1] == 'o')
                strcpy(output, argv[i+1]);
        }
    }

    //abrindo o arquivo de entrada
    arq = fopen (input, "r");
    if ( ! arq ){
       fprintf (stderr, "Erro ao abrir arquivo\n");
        exit (1);
    }

    //criando o novo arquivo
    arqs = fopen (output, "w");

    //lendo imagem
    ler_imagem(&orig, arq);
    fclose (arq);
    
    //fazendo o Filtro de redução de ruído pela média
    media(&orig, &novo);
    
    //imprimir a imagem
    imprimir_imagem(&novo, arqs);
    fclose (arqs);

    //dando free
	free(&orig);
	free(&novo);
    
}
