#include "imagem.h"

int compare (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void mediana(Imagem_t *orig, Imagem_t *novo, int n){

    strcpy(novo->tipo, orig->tipo);
    novo->altura = orig->altura;
    novo->coluna = orig->coluna;
    novo->max = orig->max;

    alocacao_matriz(novo);

    int tam = n*n;
    int mediana[tam];
    int mascara_tam = n/2;
    int m = 0;

    for (int i = 0; i < orig->altura; i++){
        for (int j = 0; j < orig->coluna; j++){
            for (int k = -mascara_tam; k <= mascara_tam; k++){
                for (int l = -mascara_tam; l <= mascara_tam; l++){
                    if(j+l >= 0 && j+l < orig->coluna && i+k >= 0 && i+k < orig->altura){
                        mediana[m] = orig->img[i+k][j+l];
                        m++;
                    }
                }
            }
            qsort(mediana ,tam , sizeof(int), compare);
            novo->img[i][j] = mediana[tam/2];
            m = 0;
            
        }
    }
    
}




int main(int argc, char **argv){

    FILE *arq;
    FILE *arqs;
    char input[MAX] , output[MAX];
    int n = 3;
    Imagem_t orig, novo;

    for (int i = 0; i < argc; i++){
        if (argv[i][0] == '-'){
            if (argv[i][1] == 'i')
                strcpy(input, argv[i+1]);
            else if (argv[i][1] == 'o')
                strcpy(output, argv[i+1]);
            else if (argv[i][1] == 'm')
                n = atoi(argv[i+1]);
        }
    }
    arq = fopen (input, "r");
    if ( ! arq ){
        printf ("Erro ao abrir arquivo");
        exit (1);
    }

    arqs = fopen (output, "w");


    ler_imagem(&orig, arq);
    fclose (arq);
    
    mediana(&orig, &novo, n);
    
    imprimir_imagem(&novo, arqs);
    fclose (arqs);
    
}
