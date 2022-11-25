#include "pilha.h"

void fpVazia(TipoPilha *pilha)
{ 
    pilha->topo = (TipoApontadorPilha) malloc(sizeof(TipoCelula));
    pilha->fundo = pilha->topo;
    pilha->topo->prox = NULL;
    pilha->tamanho = 0;
} 

int vazia(TipoPilha pilha) { return (pilha.topo == pilha.fundo); } 

void empilha(TipoItem item, TipoPilha *pilha){
    TipoApontadorPilha aux;
    aux = (TipoApontadorPilha) malloc(sizeof(TipoCelula));
    pilha->topo->item = item;
    aux->prox = pilha->topo;
    pilha->topo = aux;
    pilha->tamanho++;
} 

void desempilha(TipoPilha *pilha, TipoItem *item)
{ 
    TipoApontadorPilha aux;
    if (vazia(*pilha)) { 
        printf("\nErro: Lista Vazia"); 
        return; 
    }
    aux = pilha->topo;
    pilha->topo = aux->prox;
    *item = aux->prox->item;
} 

int tamanho(TipoPilha pilha) { return (pilha.tamanho); } 


void imprimePilhaInvertida(TipoPilha *pilhaAuxiliar)
{
    TipoApontadorPilha apAuxiliar;
    apAuxiliar = (*pilhaAuxiliar).topo->prox;
    if(vazia(*pilhaAuxiliar)){
        return;
    }
    else{
        while( apAuxiliar !=NULL)
        {
            // printf("%d %d => valor: %d => visitado: %d",apAuxiliar->Item.celulaMatriz.posicaoLinha+1, 
            // apAuxiliar->Item.celulaMatriz.posicaoColuna+1, apAuxiliar->Item.celulaMatriz.valor,apAuxiliar->Item.celulaMatriz.visitado);
            printf("%d %d",apAuxiliar->item.celulaMatriz.posicaoLinha,  apAuxiliar->item.celulaMatriz.posicaoColuna);
            printf("\n");
            apAuxiliar = apAuxiliar->prox;
        }
        printf("\n");
    }
}

void invertePilha(TipoPilha *pilha)
{  
    TipoPilha pilhaAuxiliar;
    TipoItem itemPilhaAuxiliar;

    TipoApontadorPilha ap;
    ap = pilha->topo->prox;

    fpVazia(&pilhaAuxiliar);

    if(vazia(*pilha)){ 
        return; 
    }
    else
    {
        while( ap !=NULL)
        {
            itemPilhaAuxiliar.celulaMatriz.valor = ap->item.celulaMatriz.valor;
            itemPilhaAuxiliar.celulaMatriz.posicaoLinha = ap->item.celulaMatriz.posicaoLinha;
            itemPilhaAuxiliar.celulaMatriz.posicaoColuna = ap->item.celulaMatriz.posicaoColuna;
            empilha(itemPilhaAuxiliar, &pilhaAuxiliar);
            ap = ap->prox;
        }
        printf("\n");
    }
    imprimePilhaInvertida(&pilhaAuxiliar);
}