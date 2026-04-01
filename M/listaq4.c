#include <stdio.h>

int linhaMais(int N, int m[5][5]);

int main(void)
{
    int m[5][5] = {{4, -2, -7, -3, 0},
                   {-9, 3, 0, -1, 3},                
                   {5, 4, 6, -1, -3},
                   {0, -3, -9, 1, 3},
                   {1, 3, 4, -2, -7}};

    int resultado = linhaMais(5, m);

    printf("%d\n", resultado);
    
    return 0;
}

int linhaMais(int N, int m[5][5])
{
    int indiceMaior = 0;
    int maiorContagem = -1;

    for (int i = 0; i < N; i++)
    {
        int contagemAtual = 0;
        for (int j = 0; j < N - 1; j++)
        {
            int atual = m[i][j];
            int proximo = m[i][j + 1];

            if ((atual > 0 && proximo < 0) || (atual < 0 && proximo > 0))
            {
                contagemAtual++;
            }
        }
        if (contagemAtual > maiorContagem)
        {
            maiorContagem = contagemAtual;
            indiceMaior = i;
        }
    }
    return indiceMaior;
}