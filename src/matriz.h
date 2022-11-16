#ifndef matriz_h
#define matriz_h

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define ANSI_COLOR_DEFAULT "\033[0m"
#define ANSI_COLOR_GREEN "\033[1;32m"
#define ANSI_COLOR_CYAN "\033[1;36m"

typedef struct Celula{
    int valor;
    int somaMinima;
    int qtdCaminhos;
    int posicaoLinha;
    int posicaoColuna;
    char direcao; 
    char cor[12];
}Celula;

void insereMatriz(Celula **matriz, int posicaoLinha, int posicaoColuna, int valor);
void printaMatriz(Celula **matriz, int linhas, int colunas);
void printaSoma(Celula **matriz, int linhas, int colunas);
void printaQtdCaminhos(Celula **matriz, int linhas, int colunas);
void printaDirecao(Celula **matriz, int linhas, int colunas);

Celula **inicializaMatriz(Celula **matriz, int linhas, int colunas);

#endif