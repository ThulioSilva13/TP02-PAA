#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "matriz.h"

typedef struct TipoItem {
  Celula celulaMatriz;
} TipoItem;

typedef struct TipoCelula *TipoApontadorPilha;
typedef struct TipoCelula {
  TipoItem item;
  TipoApontadorPilha prox;
} TipoCelula;

typedef struct {
  TipoApontadorPilha fundo, topo;
  int tamanho;
} TipoPilha;

void fpVazia(TipoPilha *Pilha);

int vazia(TipoPilha Pilha);

void empilha(TipoItem x, TipoPilha *Pilha);

void desempilha(TipoPilha *Pilha, TipoItem *Item);

int  tamanho(TipoPilha Pilha);

void imprimePilhaInvertida(TipoPilha *pilhaAuxiliar);

void invertePilha(TipoPilha *pilha);


