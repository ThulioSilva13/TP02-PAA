#include "galaxia.h"

void insere_matriz(Elemento **matriz, int posicaoLinha, int posicaoColuna, int valor)
{
    matriz[posicaoLinha][posicaoColuna].valor = valor;
    strcpy(matriz[posicaoLinha][posicaoColuna].cor, ANSI_COLOR_DEFAULT);
}

void printa_matriz(Elemento **matriz, int linhas, int colunas)
{
    int i, j;
    for ( i = 0; i < linhas; i++){
        printf("\n");
        for ( j = 0; j < colunas; j++){
            printf("%s", matriz[i][j].cor);
            if (matriz[i][j].valor >= 0 && matriz[i][j].valor < 10){
                printf(" %d ", matriz[i][j].valor);
            }
            else{
                printf("%d ", matriz[i][j].valor);
            }
        }
    }
    printf("\n");
    printf("%s", ANSI_COLOR_DEFAULT);
}

void libera_matriz(Elemento **matriz, int linha)
{
    int i;
    for(i = 0; i < linha; i++)
        free(matriz[i]);
    free(matriz);
}

void preenche_aleatoriamente(Elemento **matriz, int linhas, int colunas)
{
    int i, j, n;
    srand(time(NULL));
    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            if (matriz[i][j].valor == 0){ 
                insere_matriz(matriz, i, j, (rand()%33) + 1); //gerar numero aleatorio entre 1 e 9;
            }
        }
    }
}

void preenche_mesmonumero(Elemento **matriz, int linhas, int colunas){
    int i, j, n;
    srand(time(NULL));
    int num = (rand()%4) + 1; //gerar numero aleatorio entre 1 e 5;
    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            if (matriz[i][j].valor == 0){ 
                insere_matriz(matriz, i, j, num); 
            }
        }
    }
}

void preenche_unico(Elemento **matriz, int linhas, int colunas){

    srand(time(NULL));
    int num =  (rand()%8) + 2; //maior numero que faz parte do caminho_minimo (2 a 8)
    
    int x = 0; 
    int y = 0; 

    int indice = 0;
    int *prox = malloc((2)*sizeof(int));

    srand(time(NULL));

    while(1){

        if (x==(linhas-1) && y==(colunas-1)){
            matriz[x][y].valor = (rand()%num) + 1; // numero de 1 até num
            strcpy(matriz[x][y].cor , ANSI_COLOR_GREEN);
            break; 
        }

        if ((verificaPosicao(matriz, linhas, colunas, x+1, y))==true){
                matriz[x][y].valor = num;
                strcpy(matriz[x][y].cor , ANSI_COLOR_GREEN);
                matriz[x][y].visitado = true;
                x++;        
                indice++;
            }
        
        int direcao = (rand()%2); //gerar numero aleatorio de 0 a 1;

        if (direcao == 0){ //andar para baixo
            if ((verificaPosicao(matriz, linhas, colunas, x+1, y))==true){
                matriz[x][y].valor = (rand()%num) + 1; // numero de 1 até num
                strcpy(matriz[x][y].cor , ANSI_COLOR_GREEN);
                matriz[x][y].visitado = true;
                x++;        
                indice++;
            }
        }

        if (direcao == 1){ //andar para direita
            if ((verificaPosicao(matriz, linhas, colunas, x, y+1))==true){
                matriz[x][y].valor = (rand()%num) + 1; // numero de 1 até num
                strcpy(matriz[x][y].cor , ANSI_COLOR_GREEN);
                matriz[x][y].visitado = true;
                y++;        
                indice++;
            }
        }
    }

    //preencher restante das posições com numero maior que o num
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if (matriz[i][j].valor == 0){ 
                insere_matriz(matriz, i, j, (rand()%30) + num); //gerar numero aleatorio entre num e 30+num;
            }
        }
    }
}

bool verificaPosicao(Elemento **matriz, int numLinhas, int numColunas,int x, int y)
{
	if ((x >= 0 && x < numLinhas) && (y >= 0 && y < numColunas) &&
	    (matriz[x][y].visitado == false)) {	
		return true;
	} 	
	return false;
}

void printa_arquivo(Elemento **matriz, int linhas, int colunas)
{
    printf("\n==== SALVAR EM ARQUIVO =====\n");

    FILE *arquivo;

    char nome_pasta[30] = "../arquivosTeste/";
    char nome_arquivo[30];

    printf("Entre um nome para o arquivo:");
    scanf("%s", nome_arquivo);
    strcat(nome_arquivo, ".txt");

    strcat(nome_pasta, nome_arquivo);

    arquivo = fopen(nome_pasta, "w");

    if (arquivo == NULL){
        printf("\nErro: NAO FOI POSSIVEL CRIAR O ARQUIVO");
        return;
    }

    fprintf(arquivo,"%d ", linhas);
    fprintf(arquivo,"%d", colunas);

    for ( int i = 0; i < linhas; i++){
        fprintf(arquivo,"\n");
        for ( int j = 0; j < colunas; j++){
            fprintf(arquivo,"%d ",matriz[i][j].valor);
        }
    }

    fclose(arquivo);
    return;
}