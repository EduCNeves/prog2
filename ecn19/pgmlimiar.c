#include "imagem.h"

void limiar(Imagem_t *orig, Imagem_t *novo, double n){

    //copiando os argumemos do origunal e colocando no novo
    strcpy(novo->tipo, orig->tipo);
    novo->altura = orig->altura;
    novo->coluna = orig->coluna;
    novo->max = orig->max;

    //alocação da nova matriz
    alocacao_matriz(novo);

    //valor do limiar 
    int limiar = n*novo->max;
    
    //algoritmo do limiar
    for (int i = 0; i < orig->altura; i++){
        for (int j = 0; j < orig->coluna; j++){
            if (orig->img[i][j] >= limiar)
                novo->img[i][j] = novo->max;
            else 
                novo->img[i][j] = 0;
        }
    }

}

int main(int argc, char **argv){

    FILE *arq;
    FILE *arqs;
    char input[MAX] , output[MAX];
    double n = 0.5; //limiar padrao
    Imagem_t orig, novo;

    //lendo a linha de comando
    for (int i = 0; i < argc; i++){
        if (argv[i][0] == '-'){
            if (argv[i][1] == 'i')
                strcpy(input, argv[i+1]);
            else if (argv[i][1] == 'o')
                strcpy(output, argv[i+1]);
            else if (argv[i][1] == 'l')
                n = strtod(argv[i+1], NULL);
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
    
    //fazendo o filtro limiar
    limiar(&orig, &novo, n);
    
    //imprimir a imagem
    imprimir_imagem(&novo, arqs);
    fclose (arqs);
    
    //dando free
	free(&orig);
	free(&novo);

}
