#include "matriz.h"
#include "pilha.h"
//#include "hash.h"

int somaMinima(Celula **matriz, int numLinhas, int numColunas);
unsigned long long int qtdCaminhos(Celula **matriz, int numLinhas, int numColunas);
bool verificaPosicao(Celula **matriz, int numLinhas, int numColunas,int x, int y);
void procuraCaminho(Celula **matriz, int numLinhas, int numColunas);
void procurar(Celula **matriz, int numLinhas, int numColunas, int x, int y, TipoPilha* pilha);

