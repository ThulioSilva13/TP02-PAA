#include "progDinamica.h"
#include <time.h>
int somaMinima(Celula **matriz, int numLinhas, int numColunas){
    // achar soma mínima (Germano falou que essa parte é mais fácil fazendo iterativo)

    // começar da posição onde quer chegar => de tras pra frente
    // se desceria, olho pra cima
    // se iria pra direita, olho pela esquerda
    clock_t inicioSomaMinima = clock();
    double tempoSomaMinima = 0.0;
    bool verificaCima;
    bool verificaEsquerda;

    for (int i=numLinhas-1;i>=0;i--){
        for (int j=numColunas-1;j>=0;j--){

            //caso base
            if (i==numLinhas-1 && j==numColunas-1){
                matriz[i][j].somaMinima = matriz[i][j].valor;
            }

            verificaCima = verificaPosicao(matriz, numLinhas, numColunas, i-1, j);
            verificaEsquerda = verificaPosicao(matriz, numLinhas, numColunas, i, j-1);

            if (verificaCima == true){ 
                // pra cima
                if (matriz[i-1][j].somaMinima == 0){
                    matriz[i-1][j].somaMinima = matriz[i-1][j].valor + matriz[i][j].somaMinima;
                }
                else{
                    if (matriz[i-1][j].somaMinima > matriz[i-1][j].valor + matriz[i][j].somaMinima){
                        matriz[i-1][j].somaMinima = matriz[i-1][j].valor + matriz[i][j].somaMinima; 
                    }
                }
            }

            if (verificaEsquerda == true){ 
                //pra esquerda
                if (matriz[i][j-1].somaMinima == 0){
                    matriz[i][j-1].somaMinima = matriz[i][j-1].valor + matriz[i][j].somaMinima;
                }
                else{
                    if (matriz[i][j-1].somaMinima > matriz[i][j-1].valor + matriz[i][j].somaMinima){
                        matriz[i][j-1].somaMinima = matriz[i][j-1].valor + matriz[i][j].somaMinima;
                    }
                }
            }
        
        }
    }
    clock_t fimSomaMinima = clock();
    tempoSomaMinima += (double)(fimSomaMinima - inicioSomaMinima) / CLOCKS_PER_SEC;
    //printf("\n\nTempo de execução da soma mínima: %f", tempoSomaMinima);
    return matriz[0][0].somaMinima;
}
 

int qtdCaminhos(Celula **matriz, int numLinhas, int numColunas){
    clock_t inicioQuantidadeCaminhos = clock();
    double tempoQuantidadeCaminhos = 0.0;
    for (int i=numLinhas-1;i>=0;i--){
        for (int j=numColunas-1;j>=0;j--){

            //caso base
            if (i==numLinhas-1 && j==numColunas-1){
                matriz[i][j].qtdCaminhos = 1;
            }

            //se está na ultima linha só tem como vir da direita
            //entao a qtd de caminhos pra chegar nela é a qtd de caminhos pra chegar na da direita
           
            else if (i==numLinhas-1 && j!=numColunas-1){
                matriz[i][j].qtdCaminhos += matriz[i][j+1].qtdCaminhos;
            }

            //se está na ultima coluna só tem como vir de baixo
            //entao a qtd de caminhos pra chegar nela é a qtd de caminhos pra chegar na de baixo
            else if (i!=numLinhas-1 && j==numColunas-1){
                matriz[i][j].qtdCaminhos += matriz[i+1][j].qtdCaminhos;
            }

            //se tem como vir da direita e de baixo
            else{
                //se o custo de vir de baixo for o mesmo que vir de cima 
                //a qtd de caminhos pra chegar é a qtd de caminhos pra chegar na de baixo + qtd de caminhos pra chegar na de cima
                if (matriz[i][j+1].somaMinima == matriz[i+1][j].somaMinima){
                    matriz[i][j].qtdCaminhos = matriz[i][j+1].qtdCaminhos + matriz[i+1][j].qtdCaminhos;
                }
                //se o custo de vir da esquerda for maior de o de vir de baixo
                //a qtd de caminhos pra chegar com custo mínimo é qtd de caminhos pra chegar na de baixo
                //pois pra ter o custo mínimo tem que vir por ela
                else if (matriz[i][j+1].somaMinima > matriz[i+1][j].somaMinima){
                    matriz[i][j].qtdCaminhos = matriz[i+1][j].qtdCaminhos;
                   
                }
                //se o custo de vir da esquerda for menor de o de vir de baixo
                //a qtd de caminhos pra chegar com custo mínimo é qtd de caminhos pra chegar na daa esquerda
                //pois para ter o custo mínimo tem que vir por ela
                else{
                    matriz[i][j].qtdCaminhos = matriz[i][j+1].qtdCaminhos; 
                   
                }
            }  
        }
    }
    clock_t fimQuantidadeCaminhos = clock();
    tempoQuantidadeCaminhos += (double)(fimQuantidadeCaminhos - inicioQuantidadeCaminhos) / CLOCKS_PER_SEC;
    //printf("\nTempo de execução da Quantidade de caminhos: %f", tempoQuantidadeCaminhos);
    return matriz[0][0].qtdCaminhos;
}


bool verificaPosicao(Celula **matriz, int numLinhas, int numColunas,int x, int y)
{
	if ((x >= 0 && x < numLinhas) && (y >= 0 && y < numColunas)){		
		return true;
	} 
	return false;
}

void procuraCaminho(Celula **matriz, int numLinhas, int numColunas, int qtdCaminhos) {

    printf("\n%d", qtdCaminhos);

    printf("\nentra procuraCaminho");
    Celula **caminhos = inicializaMatriz(qtdCaminhos,(numLinhas+numColunas)-1);
    printf("\ninicializa caminhos");
    printf("qtd colunas = %d",(numLinhas+numColunas)-1);

    int linha = 0;
    int coluna = 0;
    printf("\ninicializa caminhos");
	procurar(matriz, numLinhas, numColunas, 0, 0, &caminhos, linha, coluna); 

	return;
}

void procurar(Celula **matriz, int numLinhas, int numColunas, int x, int y, Celula ***caminhos, int linha, int coluna)
{
    printf("\nentrar procurar");
    printf("\n coluna %d", coluna);
    *caminhos[linha][coluna]= matriz[x][y];
    printf("\n(%d, %d) -> ", caminhos[linha][coluna]->posicaoLinha, caminhos[linha][coluna]->posicaoColuna);
    printf("\n(%d, %d) -> ", matriz[x][y].posicaoLinha, matriz[x][y].posicaoColuna);


    if (((x == numLinhas - 1) && (y== numColunas-1)) ||
        ((linha == numLinhas - 1) && (coluna == numColunas-1))){
        return;
    }

    // se só tem como andar para baixo
    else if ((x != numLinhas - 1) && y== numColunas-1) {
        procurar(matriz, numLinhas, numColunas, x+1, y, caminhos,linha, coluna+1); 
    }

    // se só tem como andar para direita
    else if ((x == numLinhas - 1) && y!= numColunas-1) {
        procurar(matriz, numLinhas, numColunas, x, y+1, caminhos,linha, coluna+1); 
    }

    else{
        if (matriz[x][y+1].somaMinima == matriz[x+1][y].somaMinima) {
            // chama pra baixo
            printf("\n");
            //printf("(%d, %d) -> ", matriz[x][y].posicaoLinha, matriz[x][y].posicaoColuna);
            procurar(matriz, numLinhas, numColunas, x + 1, y, caminhos,linha, coluna+1);

            //chama pra direita
            printf("\n");
            //printf("(%d, %d) -> ", matriz[x][y].posicaoLinha, matriz[x][y].posicaoColuna);
            procurar(matriz, numLinhas, numColunas, x, y + 1, caminhos,linha, coluna+1);

        }

        else if (matriz[x][y+1].somaMinima > matriz[x+1][y].somaMinima) {
            procurar(matriz, numLinhas, numColunas, x+1, y, caminhos,linha, coluna+1);   
		        
        } else {
            procurar(matriz, numLinhas, numColunas, x, y+1, caminhos,linha, coluna+1);   
        }
    }    
	return;
}   