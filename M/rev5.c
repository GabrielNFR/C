#include <stdio.h>

int Transposta(int N, int A[N][N], int B[N][N]);

int main(void)
{
    int N;

    scanf("%d", &N);

    int A[N][N], B[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    int resultado = Transposta(N, A, B);
    printf("%d", resultado);
    
    return 0;
}

int Transposta(int N, int A[N][N], int B[N][N])
{  
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
           if (A[i][j] != B[j][i])
           {
                return 0;
           }
        }
    }
    return 1;
}