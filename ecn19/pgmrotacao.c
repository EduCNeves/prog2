#include "imagem.h"

void rotacao_simples(Imagem_t *orig, Imagem_t *novo){

	//copiando os argumemos do origunal e colocando no novo
    strcpy(novo->tipo, orig->tipo);
    novo->altura = orig->coluna;
    novo->coluna = orig->altura;
    novo->max = orig->max;

    //alocação da nova matriz
	alocacao_matriz(novo);

    unsigned char pixel;

	//rotacionando para 90 graus
    int aux_c = 0;
    for (int i = 0; i < orig->coluna; i++){
        int aux_l = orig->altura-1;
        for (int j = 0; j < orig->altura; j++){
            pixel = orig->img[aux_l][aux_c];
            novo->img[i][j] = pixel;
            --aux_l; 
        }

        ++aux_c;
    }

}

void rotocao_livre(Imagem_t *orig, Imagem_t *novo, int graus){

    strcpy(novo->tipo, orig->tipo);
	
	//calculando a nova altura e a nova coluna
	int h = sqrt( (orig->altura*orig->altura) + (orig->coluna*orig->coluna) );
	novo->altura = h;
	novo->coluna = h;

    novo->max = 255;

	//tranformando graus para radianos
	double rad = - ((graus-180)*M_PI) / 180;

	//calculando o centro das matriz
	int orig_centro_x = (orig->coluna)/2;
    int orig_centro_y = (orig->altura)/2;
    int nova_centro_x = (novo->coluna)/2;
    int nova_centro_y = (novo->altura)/2;

	//alocação da nova matriz
    alocacao_matriz(novo);

	//colocando branco na matriz
	for (int i=0; i < novo->altura; i++)
    	for (int j=0; j < novo->coluna; j++)
      		novo->img[i][j] = novo->max;  

    int aux_c, aux_l;
	
    for (int i = 0; i < novo->altura; i++){
        for (int j = 0; j < novo->coluna; j++){

			// converte para o plano cartesiano 
			int x = j - nova_centro_x; 
            int y = - (i - nova_centro_y); 

			//calculando o angulo da novo matriz
            aux_l = (x*cos(rad) - y*sin(rad)) + orig_centro_y;
			aux_c = (x*sin(rad) + y*cos(rad)) + orig_centro_x;

			//colocando a imagem orignal na nova imagem 
			if ( aux_l >= 0 && aux_c >=0 && aux_l < orig->altura && aux_c < orig->coluna ){
				novo->img[i][j] = orig->img[aux_l][aux_c];
			}

        }
    }

}

int main(int argc, char **argv){

    FILE *arq;
    FILE *arqs;
	int n = 90; //graus
    char input[MAX] , output[MAX];
    Imagem_t orig, novo;

	//lendo a linha de comando
    for (int i = 0; i < argc; i++){
        if (argv[i][0] == '-'){
            if (argv[i][1] == 'i') 
                strcpy(input, argv[i+1]);
            else if (argv[i][1] == 'o')
                strcpy(output, argv[i+1]);
            else if (argv[i][1] == 'a')
                n = atoi(argv[i+1]);
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

	//fazendo a rotação
	if( n == 90 ){
    	rotacao_simples(&orig, &novo);
	}
	else{ 
		rotocao_livre(&orig, &novo, n);
	}

	//imprimir a imagem
    imprimir_imagem(&novo, arqs);
    fclose (arqs);

	//dando free
	free(&orig);
	free(&novo);
    
}
