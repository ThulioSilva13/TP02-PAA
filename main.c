#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./src/lerArquivo.h"
#include "./src/matriz.h"

int menu(int opcao)
{
    printf("\n\n=========== MENU ===========");
    printf("\n0) Sair");
    printf("\n1) Ler arquivo e montar a matriz");
    printf("\nEscolha: ");
    scanf("%d",&opcao);
    return opcao;
}

int main(int argc, char **argv)
{
    Celula **matriz;
    int opcao = -1;
    char **nomeArquivo;
    int numLinhas, numColunas;

    nomeArquivo = malloc(sizeof(char) * 30);
    *nomeArquivo = argv[1];
   
    while(opcao != 0)
    {
        opcao = menu(opcao);

        switch (opcao)
        {
        case 0:
            break;

        case 1:
            if (*nomeArquivo == NULL)
            {
                char nomeArqv[30];
                printf("\nDigite o nome do arquivo .txt: ");            
                scanf("%s", nomeArqv);
                *nomeArquivo = nomeArqv;               
            }
            if (lerArquivoPrincipal(nomeArquivo, &numLinhas,&numColunas, &matriz) == 1)
            {
                if (numLinhas > 100 || numColunas > 100)
                {
                    printf("\nNumero de linhas ou colunas maiores que 100.");
                    break;
                }
            }  

            printaMatriz(matriz,numLinhas,numColunas);

            //achar soma mínima (Germano falou que essa parte é mais fácil fazendo iterativo)

            int i=numLinhas-1;
            int j=numColunas-1;
            //começar da posição onde quer chegar => de tras pra fernte
            //se desceria, olho pra cima
            //se iria pra direita olho pela esquerda

            //printf("\nDo fim pro inicio:");

            while(true){
                if ((i==0)&&(j==0)){ //se chegar na posição[0][0] = "inicio" do caminho onde está a soma minima
                    printf("\n\nSoma Minima : %d",matriz[i][j].valor);
                    break;
                }

                else if ((i!=0)&&(j==0)){ //se ainda não esta na primeira mas esta na primeira coluna
                    //só posso olhar esquerda
                    matriz[i-1][j].valor += matriz[i][j].valor; //incrementa valor na posição a esquerda 
                    i--; //decrementa i para passar a olhar a partir da posição a esquerda
                }

                else if ((i==0)&&(j!=0)){ //se esta na primeira linha mas ainda nao esta na primeira coluna
                    //só posso olhar pra cima
                    matriz[i][j-1].valor += matriz[i][j].valor; //incrementa valor na posição a cima 
                    j--; //decrementa j para passar a olhar a partir da posição a cima
                }
                
                else { //se nao esta na nem primeira linha nem na ultima coluna
                    //olhar pra cima e pra esquerda
                    //compara valor //E SE FOR IGUAL? INDICOU DE TER MAIS DE UM CAMINHO COM A MESMA SOMA
                    //e pega menor

                    if ((matriz[i-1][j].valor)>=(matriz[i][j-1].valor)){ //se a cima maior => pegar a esquerda
                        matriz[i][j-1].valor += matriz[i][j].valor;
                        j --;
                    }
                    else{
                        matriz[i-1][j].valor += matriz[i][j].valor; //se a baixo maior => pegar a cima
                        i --;
                    }
                }
            }

            break;

        default:
            break;

        }
    }

    return 0;
}