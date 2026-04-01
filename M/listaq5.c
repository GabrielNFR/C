#include <stdio.h>

int menorSomaP(int N, int m[][5], int p[]);

int main(void)
{   
    int m[5][5] = {{4, -2, -7, -3, 0},
                   {-9, 3, 0, -1, 3},                
                   {5, 4, 6, -1, -3},
                   {0, -3, -9, 1, 3},
                   {1, 3, 4, -2, -7}};

    int p[5] = {3, 6, 9, 2, 1};

    int resultado = menorSomaP(5, m, p);
    
    printf("%d\n", resultado);

    return 0;
}

int menorSomaP(int N, int m[][5], int p[])
{
    int colunaMenor = 0;
    float menorSoma;

    for (int j = 0; j < N; j++)
    {
        float somaPonderadaAtual = 0.0;
        for (int i = 0; i < N; i++)
        {
            somaPonderadaAtual += m[i][j] * p[i];     
        }
        if (j == 0)
        {
            menorSoma = somaPonderadaAtual;
        }
        if (somaPonderadaAtual < menorSoma)
        {
            menorSoma = somaPonderadaAtual;
            colunaMenor = j;
        }
    }
    return colunaMenor;
}