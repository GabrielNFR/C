#include <stdio.h>
#include <limits.h>

#define MAXR 200
#define MAXC 200

int submatriz(int R, int C, int K, int A[R][MAXC], int *linha_vencedora, int *coluna_vencedora)
{
    int maior_soma = INT_MIN;
    for (int i = 0; i <= R - K; i++)
    {
        for (int j = 0; j <= C - K; j++)
        {
            int somaAtual = 0;
            for (int a = i; a <= i + K - 1; a++)
            {
                for (int b = j; b <= j + K - 1; b++)
                {
                    somaAtual += A[a][b];
                }
            }
            if (somaAtual > maior_soma)
            {
                maior_soma = somaAtual;
                *linha_vencedora = i;
                *coluna_vencedora = j;
            }
        }
    }
    return maior_soma;
}

int main() {
    int R, C, K;
    int A[MAXR][MAXC];

    if (scanf("%d %d %d", &R, &C, &K) != 3) return 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int linha, coluna;

    int maior_soma = submatriz(R, C, K, A, &linha, &coluna);

    printf("%d %d %d", maior_soma, linha, coluna);

    return 0;
}
