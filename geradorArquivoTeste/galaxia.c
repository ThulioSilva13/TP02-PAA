#include "galaxia.h"

void insere_matriz(Elemento **matriz, int posicaoLinha, int posicaoColuna, int valor)
{
    matriz[posicaoLinha][posicaoColuna].valor = valor;
    strcpy(matriz[posicaoLinha][posicaoColuna].cor, ANSI_COLOR_DEFAULT);
}

void printa_matriz(Elemento **matriz, int linhas, int colunas)
{
    int i, j;
    for ( i = 0; i < linhas; i++){
        printf("\n");
        for ( j = 0; j < colunas; j++){
            printf("%s", matriz[i][j].cor);
            if (matriz[i][j].valor >= 0 && matriz[i][j].valor < 10){
                printf(" %d ", matriz[i][j].valor);
            }
            else{
                printf("%d ", matriz[i][j].valor);
            }
        }
    }
    printf("\n");
    printf("%s", ANSI_COLOR_DEFAULT);
}

void libera_matriz(Elemento **matriz, int linha)
{
    int i;
    for(i = 0; i < linha; i++)
        free(matriz[i]);
    free(matriz);
}

void preenche_aleatoriamente(Elemento **matriz, int linhas, int colunas)
{
    int i, j, n;
    srand(time(NULL));
    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            if (matriz[i][j].valor == 0){ 
                insere_matriz(matriz, i, j, (rand()%33) + 1); //gerar numero aleatorio entre 1 e 9;
            }
        }
    }
}

void printa_arquivo(Elemento **matriz, int linhas, int colunas)
{
    printf("\n==== SALVAR EM ARQUIVO =====\n");

    FILE *arquivo;

    char nome_pasta[30] = "../arquivosTeste/";
    char nome_arquivo[30];

    printf("Entre um nome para o arquivo:");
    scanf("%s", nome_arquivo);
    strcat(nome_arquivo, ".txt");

    strcat(nome_pasta, nome_arquivo);

    arquivo = fopen(nome_pasta, "w");

    if (arquivo == NULL){
        printf("\nErro: NAO FOI POSSIVEL CRIAR O ARQUIVO");
        return;
    }

    fprintf(arquivo,"%d ", linhas);
    fprintf(arquivo,"%d", colunas);

    for ( int i = 0; i < linhas; i++){
        fprintf(arquivo,"\n");
        for ( int j = 0; j < colunas; j++){
            fprintf(arquivo,"%d ",matriz[i][j].valor);
        }
    }

    fclose(arquivo);
    return;
}