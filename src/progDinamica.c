#include "progDinamica.h"

int somaMinima(Celula **matriz, int numLinhas, int numColunas){
    // achar soma mínima (Germano falou que essa parte é mais fácil fazendo iterativo)

    // começar da posição onde quer chegar => de tras pra frente
    // se desceria, olho pra cima
    // se iria pra direita, olho pela esquerda

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
                    //matriz[i-1][j].direcao = 'b';
                }
                else{
                    if (matriz[i-1][j].somaMinima > matriz[i-1][j].valor + matriz[i][j].somaMinima){
                        matriz[i-1][j].somaMinima = matriz[i-1][j].valor + matriz[i][j].somaMinima;
                        //matriz[i-1][j].direcao = 'b';
                    }

                    // if(matriz[i-1][j].somaMinima == matriz[i-1][j].valor + matriz[i][j].somaMinima){
                    //     matriz[i-1][j].direcao = 'x';
                    // }
                }
            }

            if (verificaEsquerda == true){ 
                //pra esquerda
                if (matriz[i][j-1].somaMinima == 0){
                    matriz[i][j-1].somaMinima = matriz[i][j-1].valor + matriz[i][j].somaMinima;
                    //matriz[i][j-1].direcao = 'd';
                }
                else{
                    if (matriz[i][j-1].somaMinima > matriz[i][j-1].valor + matriz[i][j].somaMinima){
                        matriz[i][j-1].somaMinima = matriz[i][j-1].valor + matriz[i][j].somaMinima;
                        //matriz[i][j-1].direcao = 'd';
                    }

                    // if (matriz[i][j-1].somaMinima == matriz[i][j-1].valor + matriz[i][j].somaMinima){
                    //     matriz[i][j-1].direcao = 'x';
                    // }
                    
                }
            }

            
            // if (verificaCima == true && verificaEsquerda == true){ 

            //     // pra cima
            //     if (matriz[i-1][j].somaMinima == 0){
            //         matriz[i-1][j].somaMinima = matriz[i-1][j].valor + matriz[i][j].somaMinima;
            //     }
            //     else{
            //         if (matriz[i-1][j].somaMinima > matriz[i-1][j].valor + matriz[i][j].somaMinima){
            //             matriz[i-1][j].somaMinima = matriz[i-1][j].valor + matriz[i][j].somaMinima;
            //         }
            //     }
                

            //     //pra esquerda
            //     if (matriz[i][j-1].somaMinima == 0){
            //         matriz[i][j-1].somaMinima = matriz[i][j-1].valor + matriz[i][j].somaMinima;
            //     }
            //     else{
            //         if (matriz[i][j-1].somaMinima > matriz[i][j-1].valor + matriz[i][j].somaMinima){
            //             matriz[i][j-1].somaMinima = matriz[i][j-1].valor + matriz[i][j].somaMinima;
            //         }
            //     }
            // }

            // else if (verificaCima == true && verificaEsquerda == false){
            //     // pra cima
            //     if (matriz[i-1][j].somaMinima == 0){
            //         matriz[i-1][j].somaMinima = matriz[i-1][j].valor + matriz[i][j].somaMinima;
            //     }
            //     else{
            //         if (matriz[i-1][j].somaMinima > matriz[i-1][j].valor + matriz[i][j].somaMinima){
            //             matriz[i-1][j].somaMinima = matriz[i-1][j].valor + matriz[i][j].somaMinima;
            //         }
            //     }
            // }

            // else {
            //     //pra esquerda
            //     if (matriz[i][j-1].somaMinima == 0){
            //         matriz[i][j-1].somaMinima = matriz[i][j-1].valor + matriz[i][j].somaMinima;
            //     }
            //     else{
            //         if (matriz[i][j-1].somaMinima > matriz[i][j-1].valor + matriz[i][j].somaMinima){
            //             matriz[i][j-1].somaMinima = matriz[i][j-1].valor + matriz[i][j].somaMinima;
            //         }
            //     }
            // }

                

        //         //matriz[i][j-1].somaMinima = matriz[i][j-1].valor + matriz[i][j].somaMinima;
        //        // matriz[i-1][j].somaMinima = matriz[i-1][j].valor + matriz[i][j].somaMinima;

        //         if (matriz[i-1][j].valor > matriz[i][j-1].valor){
        //             //se pra esquerda for menor
        //             //esquerda = valor dele + minimo atual
        //             if(matriz[i][j-1].somaMinima > matriz[i][j-1].valor + matriz[i][j].somaMinima
        //                 && matriz[i][j-1].somaMinima != 0)
        //             {
        //                 matriz[i][j-1].somaMinima = matriz[i][j-1].valor + matriz[i][j].somaMinima;
        //                 matriz[i-1][j].somaMinima = matriz[i-1][j].valor + matriz[i][j].somaMinima;
        //             }
        //         }
        //         else{
                    
        //             //se pra cima for menor
        //             //cima = valor dele + minimo atual
        //             if(matriz[i-1][j].somaMinima > matriz[i-1][j].valor + matriz[i][j].somaMinima
        //                  && matriz[i-1][j].somaMinima != 0)
        //             {
        //                 matriz[i-1][j].somaMinima = matriz[i-1][j].valor + matriz[i][j].somaMinima;
        //                 matriz[i][j-1].somaMinima = matriz[i][j-1].valor + matriz[i][j].somaMinima;
        //             } 
        //         }
        //     } 

        //     if (verificaCima == true && verificaEsquerda == false){
        //         if(matriz[i-1][j].somaMinima > matriz[i-1][j].valor + matriz[i][j].somaMinima
        //              && matriz[i-1][j].somaMinima != 0)
        //         {
        //             matriz[i-1][j].somaMinima = matriz[i-1][j].valor + matriz[i][j].somaMinima;
        //             matriz[i][j-1].somaMinima = matriz[i][j-1].valor + matriz[i][j].somaMinima;
        //         } 
        //     }

        //     if (verificaCima == false && verificaEsquerda == true){
        //         if(matriz[i][j-1].somaMinima > matriz[i][j-1].valor + matriz[i][j].somaMinima
        //              && matriz[i][j-1].somaMinima != 0)
        //         {
        //             matriz[i][j-1].somaMinima = matriz[i][j-1].valor + matriz[i][j].somaMinima;
        //             matriz[i-1][j].somaMinima = matriz[i-1][j].valor + matriz[i][j].somaMinima;
        //         }  
        //     }
        // }
        }
    }

    return matriz[0][0].somaMinima;
}

bool verificaPosicao(Celula **matriz, int numLinhas, int numColunas,int x, int y)
{
	if ((x >= 0 && x < numLinhas) && (y >= 0 && y < numColunas)){		
		return true;
	} 
	return false;
}
            