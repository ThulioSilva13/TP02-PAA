#include "matriz.h"
#include <limits.h>

Celula **inicializaMatriz(int linhas, int colunas){
    int i;
    Celula **matriz;
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

void insereMatriz(Celula **matriz, int posicaoLinha, int posicaoColuna, int valor){
    matriz[posicaoLinha][posicaoColuna].valor = valor;
    matriz[posicaoLinha][posicaoColuna].somaMinima = 0; 
    matriz[posicaoLinha][posicaoColuna].qtdCaminhos = 0; 
    matriz[posicaoLinha][posicaoColuna].posicaoLinha = posicaoLinha+1;
    matriz[posicaoLinha][posicaoColuna].posicaoColuna = posicaoColuna+1;
    strcpy(matriz[posicaoLinha][posicaoColuna].cor, ANSI_COLOR_DEFAULT);
}

void printaMatriz(Celula **matriz, int linhas, int colunas){
    int i, j;
    printf("\n");
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
    printf("%s", ANSI_COLOR_DEFAULT);
}

void printaSomaMinima(Celula **matriz, int linhas, int colunas){
    int i, j;
    for ( i = 0; i < linhas; i++){
        printf("\n");
        for ( j = 0; j < colunas; j++){
            //printf("%s", matriz[i][j].cor);
            if (matriz[i][j].somaMinima >= 0 && matriz[i][j].somaMinima < 10){
                printf(" %d ", matriz[i][j].somaMinima);
            }
            else{
                printf("%d ", matriz[i][j].somaMinima);
            }
        } 
    }
    printf("\n"); 
}

void printaQtdCaminhos(Celula **matriz, int linhas, int colunas){
    int i, j;
    for ( i = 0; i < linhas; i++){
        printf("\n");
        for ( j = 0; j < colunas; j++){
            //printf("%s", matriz[i][j].cor);
            if (matriz[i][j].qtdCaminhos >= 0 && matriz[i][j].qtdCaminhos  < 10){
                printf(" %d ", matriz[i][j].qtdCaminhos );
            }
            else{
                printf("%d ", matriz[i][j].qtdCaminhos);
            }
        } 
    }
    printf("\n"); 
}

