#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "./src/lerArquivo.h"
#include "./src/matriz.h"
#include "./src/progDinamica.h"

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

            //printaMatriz(matriz,numLinhas,numColunas);
            
            printf("\nSoma Minima = %d\n", somaMinima(matriz, numLinhas, numColunas));

            //printaSoma(matriz,numLinhas,numColunas);

            int qtd =  qtdCaminhos(matriz, numLinhas, numColunas);

            printf("\nQuantidade de Caminhos = %d\n", qtd);

            //printaQtdCaminhos(matriz,numLinhas,numColunas);

            if (qtd==1){
                printf("\n= ");
                mostraUmCaminho(matriz, numLinhas, numColunas, 0, 0);
                printaMatriz(matriz,numLinhas,numColunas);
            }

            else{
                int monstrarCaminhos;
                printf("\n1) Apresentar um dos caminhos com custo mínimo");
                printf("\n2) Apresentar todos caminhos com custo mínimo");
                printf("\n3) Voltar para o menu ");
                printf("\nEscolha: ");
                scanf("%d",&monstrarCaminhos);

                if (monstrarCaminhos == 1){
                    printf("\n= ");
                    mostraUmCaminho(matriz, numLinhas, numColunas, 0, 0);
                }

                if (monstrarCaminhos == 2){
                    printf("\n");
                    mostraTodosCaminhos(matriz, numLinhas, numColunas, qtd);
                }
            }
            
  
        default:
            break;
        }
    }

    return 0;
}
