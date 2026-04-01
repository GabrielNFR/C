#include <stdio.h>

int main(void) {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    int A[50][50];
    int B[50][50] = {0};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // TODO: construir B como rotacao 90 graus horario de A
    // Regra: B[j][N-1-i] = A[i][j]
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            B[j][N-1-i] = A[i][j];
        }
    }

    // TODO: imprimir B no formato: N linhas, N inteiros por linha separados por espaco
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j > 0)
            {
                printf(" ");
            }
            printf("%d", B[i][j]);
        }
        printf("\n");
    }

    // TODO: verificar se B e identidade e imprimir "IDENTIDADE" ou "NAO"

    int identidade = 1;

    for (int i = 0; i < N && identidade; i++)
    {
        for (int j = 0; j < N && identidade; j++)
        {
            if (i == j && B[i][j] != 1)
            {
                identidade = 0;                
            }
            if (i != j && B[i][j] != 0)
            {
                identidade = 0;
            }
        }
    }

    if (identidade)
    {
        printf("IDENTIDADE");
    }
    else
    {
        printf("NAO");
    }

    return 0;
}
