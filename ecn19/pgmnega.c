#include "imagem.h"

void negativo(Imagem_t *orig, Imagem_t *neg){

    unsigned char pixel;
    
    //copiando os argumemos do origunal e colocando no novo
    strcpy(neg->tipo, orig->tipo);
    neg->altura = orig->altura;
    neg->coluna = orig->coluna;
    neg->max = orig->max;

    //alocação da neg matriz
    alocacao_matriz(neg);

    //algoritmo do negativo
    for (int i = 0; i < orig->altura; i++)
        for (int j = 0; j < orig->coluna; j++){
            pixel = orig->img[i][j];
            //diminuindo do max
            pixel = orig->max - pixel;
            neg->img[i][j] = pixel;
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
    
    //fazendo o filtro negativo
    negativo(&orig, &novo);

    //imprimir a imagem
    imprimir_imagem(&novo, arqs);
    fclose (arqs);

    //dando free
	free(&orig);
	free(&novo);
    
}
