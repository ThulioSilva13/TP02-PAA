#include "matriz.h"
//#include "pilha.h"
//#include "hash.h"

int somaMinima(Celula **matriz, int numLinhas, int numColunas);
int qtdCaminhos(Celula **matriz, int numLinhas, int numColunas);
bool verificaPosicao(Celula **matriz, int numLinhas, int numColunas,int x, int y);
void mostraUmCaminho(Celula **matriz, int numLinhas, int numColunas, int x, int y);
void mostraTodosCaminhos(Celula **matriz, int numLinhas, int numColunas, int qtdCaminhos);
void procurarTodos(Celula **matriz, int numLinhas, int numColunas, int x, int y);

