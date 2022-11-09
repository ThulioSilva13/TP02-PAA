#include "lerArquivo.h"
#include "matriz.h"

int lerArquivoPrincipal(char **nomeArquivo, int *l, int *c, Celula ***matriz)
{
    int linhas, colunas;

    char *cadaNumero;
    char nomepasta[100] = "./arquivosTeste/";
    char *cadaLinha;
    cadaLinha = malloc(sizeof(char) * 900);
    
    strcat(nomepasta, *nomeArquivo);
    strcat(nomepasta, ".txt");
    //printf("%s\n",nomepasta);

    FILE *arquivoDeEntrada;
    
    if ((arquivoDeEntrada = fopen(nomepasta, "r")) == NULL)
    {
        *nomeArquivo = NULL;
        printf("\nArquivo nao encontrado!");
        return 0;
    }
    fscanf(arquivoDeEntrada, "%d %d", &linhas, &colunas);
    *l = linhas;
    *c = colunas;
    *matriz = inicializaMatriz(*matriz,linhas,colunas);
    
    int posicaoLinha = 0;

    while (!feof(arquivoDeEntrada)){
        
        int posicaoColuna  = 0;
        fscanf(arquivoDeEntrada," %[^\n]s",cadaLinha);         
        if (cadaLinha) // se foi possível ler
        { 
            cadaNumero = strtok(cadaLinha, " ");
            while (cadaNumero != NULL)
            {
                insereMatriz(*matriz, posicaoLinha, posicaoColuna, atoi(cadaNumero));
                posicaoColuna++;
                cadaNumero = strtok(NULL, " ");
            }                
        }
        posicaoLinha++;
    }
    fclose(arquivoDeEntrada);
    *nomeArquivo = NULL;
    return 1;
}
