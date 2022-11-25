#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

#define M 7
#define N 7      
#define TAMALFABETO 256

/* typedef unsigned int  TipoPesos[n]; */
typedef int TipoChave[N];
typedef unsigned TipoPesos[N][TAMALFABETO];
typedef struct TipoItem {
  /* outros componentes */
  TipoChave Chave;
} TipoItem;
typedef unsigned int TipoIndice;
typedef struct TipoCelula* TipoApontador;
typedef struct TipoCelula {
  TipoItem Item;
  TipoApontador Prox;
} TipoCelula;
typedef struct TipoLista {
  TipoCelula *Primeiro, *Ultimo;
} TipoLista;
typedef TipoLista TipoDicionario[M];
// TipoDicionario Tabela;
// TipoItem Elemento;
// TipoPesos p;
// TipoApontador i;