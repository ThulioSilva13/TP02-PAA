#include "progDinamica.h"
#include <time.h>
int somaMinima(Celula **matriz, int numLinhas, int numColunas){
    // achar soma mínima (Germano falou que essa parte é mais fácil fazendo iterativo)

    // começar da posição onde quer chegar => de tras pra frente
    // se desceria, olho pra cima
    // se iria pra direita, olho pela esquerda
    clock_t inicio = clock();
    double tempo = 0.0;
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
                    matriz[i-1][j].direcao = 'b';
                }
                else{
                    if (matriz[i-1][j].somaMinima > matriz[i-1][j].valor + matriz[i][j].somaMinima){
                        matriz[i-1][j].somaMinima = matriz[i-1][j].valor + matriz[i][j].somaMinima; 
                        matriz[i-1][j].direcao = 'b';
                    }

                    if(matriz[i-1][j].somaMinima == matriz[i-1][j].valor + matriz[i][j].somaMinima){
                        matriz[i-1][j].direcao = 'x';
                    }
                }
            }

            if (verificaEsquerda == true){ 
                //pra esquerda
                if (matriz[i][j-1].somaMinima == 0){
                    matriz[i][j-1].somaMinima = matriz[i][j-1].valor + matriz[i][j].somaMinima;
                    matriz[i][j-1].direcao = 'd';
                }
                else{
                    if (matriz[i][j-1].somaMinima > matriz[i][j-1].valor + matriz[i][j].somaMinima){
                        matriz[i][j-1].somaMinima = matriz[i][j-1].valor + matriz[i][j].somaMinima;
                        matriz[i][j-1].direcao = 'd';
                    }

                    if (matriz[i][j-1].somaMinima == matriz[i][j-1].valor + matriz[i][j].somaMinima){
                        matriz[i][j-1].direcao = 'x';
                    }
                    
                }
                matriz[i][j].visitado = true;
            }
        
        }
    }
    clock_t fim = clock();
    tempo += (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\n");
    printf("Tempo de execução: %f", tempo);
    return matriz[0][0].somaMinima;
}
 

int qtdCaminhos(Celula **matriz, int numLinhas, int numColunas){

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
    return matriz[0][0].qtdCaminhos;
}


bool verificaPosicao(Celula **matriz, int numLinhas, int numColunas,int x, int y)
{
	if ((x >= 0 && x < numLinhas) && (y >= 0 && y < numColunas)){		
		return true;
	} 
	return false;
}
            