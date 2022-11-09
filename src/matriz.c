#include "matriz.h"

void insereMatriz(Celula **matriz, int posicaoLinha, int posicaoColuna, int valor){
    matriz[posicaoLinha][posicaoColuna].valor = valor;
    matriz[posicaoLinha][posicaoColuna].posicaoLinha = posicaoLinha+1;
    matriz[posicaoLinha][posicaoColuna].posicaoColuna = posicaoColuna+1;
    matriz[posicaoLinha][posicaoColuna].direcao = 'X'; //'B' = baixo e 'D' = cima
    strcpy(matriz[posicaoLinha][posicaoColuna].cor, ANSI_COLOR_DEFAULT);
}

void printaMatriz(Celula **matriz, int linhas, int colunas){
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
}

Celula **inicializaMatriz(Celula **matriz, int linhas, int colunas){
    int i;
    matriz = (Celula **)malloc(sizeof(Celula *)*linhas);

    if( matriz == NULL){
        printf("Memoria insuficiente.\n");
        return NULL;
    }
    for (i=0; i < linhas; i++){
        matriz[i] = (Celula *)malloc(sizeof(Celula)*colunas);
        if( matriz[i] == NULL){
            printf("Memoria insuficiente.\n");
            return NULL;
        }
    }
    return matriz;
}