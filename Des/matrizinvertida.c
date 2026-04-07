#include <stdio.h>
#include <stdlib.h>

int** criarMatrizInvertida(int **matriz, int linhas, int colunas)
{
    int **M = (int**)malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++)
    {
        M[i] = (int*)malloc(colunas * sizeof(int));
    }

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            M[i][j] = matriz[linhas - 1 - i][colunas - 1 - j];
        }
    }

    return M;
}

int main(void)
{   
    int linhas = 3;
    int colunas = 3;

    int **matriz = (int**)malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = (int*)malloc(colunas * sizeof(int));
    }

    int contador = 1;
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            matriz[i][j] = contador++;
        }
    }

    int **M = criarMatrizInvertida(matriz, linhas, colunas);

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < linhas; i++)
    {
        free(matriz[i]);
        free(M[i]);
    }
    free(matriz);
    free(M);

    return 0;
}

