#include <stdio.h>

int main(void) {
    int R, C;
    scanf("%d %d", &R, &C);

    int mat[50][50];
    int soma[50];

    // TODO: Leia a matriz em mat e calcule a soma de cada linha em soma
    for (int i = 0; i < R; i++)
    {
        soma[i] = 0;
        for (int j = 0; j < C; j++)
        {
            scanf("%d", &mat[i][j]);
            soma[i] += mat[i][j];
        }
    }
    // TODO: Encontre o índice da linha com maior soma (menor índice em caso de empate)
    int maiorSoma = soma[0];
    int indice = 0;

    for (int i = 1; i < R; i++)
    {
        if (soma[i] > maiorSoma)
        {
            maiorSoma = soma[i];
            indice = i;
        }
    }

    // TODO: Imprima o vetor soma (R inteiros separados por espaço) e depois o índice
    printf("%d", soma[0]);

    for (int i = 1; i < R; i++)
    {
        printf(" %d", soma[i]);
    }

    printf("\n%d", indice);

    return 0;
}