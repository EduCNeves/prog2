#include "imagem.h"

void lbp(Imagem_t *orig, Imagem_t *novo){

    //copiando os argumemos do origunal e colocando no novo
    strcpy(novo->tipo, orig->tipo);
    novo->altura = orig->altura;
    novo->coluna = orig->coluna;
    novo->max = 255;

    //alocação da neg matriz
    alocacao_matriz(novo);

    //matriz do lbp
    int matriz_lbp[3][3] = 
    {
        {  1,  2, 4 },
        {  8,  0, 16 },
        {  32, 64,  128 }
    };

    //matriz auxiliar
    int aux[3][3];

    //algortimo Filtro LBP (Local Binary Patterns)
    int aux_l, aux_c, lbp_l, lbp_c;
    int soma = 0;
    for (int i = 0; i < orig->altura; i++){ //percore a imagem original
        for (int j = 0; j < orig->coluna; j++){ 
            aux_l = i;
            aux_c = j;
            lbp_l = 0;
            for (int k = aux_l-1; k <= aux_l+1 ; k++){ //percore a matriz aux
                lbp_c = 0;
                for (int l = aux_c-1; l <= aux_c+1; l++){
                    if ( k >= 0 && l >=0 && k < orig->altura && l < orig->coluna ){ //vejo se os valores do indice esta fora da matriz
                        if (orig->img[k][l] <= orig->img[aux_l][aux_c]) { //vejo se os pixels vizinhos são maior ou igual 
                            aux[lbp_l][lbp_c] = 1; //coloco 1
                            aux[lbp_l][lbp_c] = aux[lbp_l][lbp_c]*matriz_lbp[lbp_l][lbp_c]; //faço a multiplicação da matriz lbp pela matriz aux
                            soma = aux[lbp_l][lbp_c] + soma; //faço a soma dos valores da matriz lbp
                        }
                        else{ 
                            aux[lbp_l][lbp_c] = 0; //coloco 0
                            aux[lbp_l][lbp_c] = aux[lbp_l][lbp_c]*matriz_lbp[lbp_l][lbp_c]; //faço a multiplicação da matriz lbp pela matriz aux
                            soma = aux[lbp_l][lbp_c] + soma; //faço a soma dos valores da matriz lbp
                        }
                    }
                    lbp_c++;
                }
                lbp_l++;
            } 
            novo->img[i][j] = soma; //coloca a soma da matriz aux no pixel da nova matriz
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
        printf ("Erro ao abrir arquivo");
        exit (1);
    }

    //criando o novo arquivo
    arqs = fopen (output, "w");

    //lendo imagem
    ler_imagem(&orig, arq);
    fclose (arq);
    
    //fazendo o Filtro LBP (Local Binary Patterns)
    lbp(&orig, &novo);
    
    //imprimir a imagem
    imprimir_imagem(&novo, arqs);
    fclose (arqs);

    //dando free
	free(&orig);
	free(&novo);
    
    
}
