#include <stdio.h>

int IdMaiorElemento(int N, int V[N]);

int main(void)
{   
    int N;

    scanf("%d", &N);

    int V[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &V[i]);
    }
    
    int maiorIdx = IdMaiorElemento(N, V);
    
    printf("%d", maiorIdx);

    return 0;
}

int IdMaiorElemento(int N, int V[N])
{
    int maior = V[0];
    int idx;

    for (int i = 1; i < N; i++)
    {
        if (V[i] > maior)
        {
            maior = V[i];
            idx = i;
        }
    }
    return idx;
}