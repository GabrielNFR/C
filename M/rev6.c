#include <stdio.h>
#include <limits.h>

int ColMaiorSoma(int N, int M[N][N]);

int main(void)
{
    int N;
    scanf("%d", &N);

    int M[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &M[i][j]);
        }
    }

    int maiorCol = ColMaiorSoma(N, M);
    printf("%d", maiorCol);

    return 0;
}

int ColMaiorSoma(int N, int M[N][N])
{
    int maiorSoma = INT_MIN;
    int idx;
    for (int j = 0; j < N; j++)
    {
        int somaAtual = 0;
        for (int i = 0; i < N; i++)
        {
            somaAtual += M[i][j];
        }
        if (somaAtual > maiorSoma)
        {
            maiorSoma = somaAtual;
            idx = j;
        }
    }
    return idx;
}