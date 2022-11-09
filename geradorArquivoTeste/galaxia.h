#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define ANSI_COLOR_DEFAULT "\033[0m"
#define ANSI_COLOR_GREEN "\033[1;32m"

typedef struct Elemento {
    int valor;
    bool visitado; 
    char cor[12];
} Elemento;

void insere_matriz(Elemento **matriz, int posicaoLinha, int posicaoColuna, int valor);
void printa_matriz(Elemento **matriz, int linhas, int colunas);
void libera_matriz(Elemento **matriz, int linhas);

void preenche_aleatoriamente(Elemento **matriz, int linhas, int colunas);

void printa_arquivo(Elemento **matriz, int linhas, int colunas);