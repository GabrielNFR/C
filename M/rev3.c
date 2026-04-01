#include <stdio.h>

int SomaADP(int N, int m[5][5]);

int main(void)
{   
    int m[5][5] = {{4, -2, -7, -3, 0},
                   {-9, 3, 0, -1, 3},                
                   {5, 4, 6, -1, -3},
                   {0, -3, -9, 1, 3},
                   {1, 3, 4, -2, -7}};

    int soma = SomaADP(5, m);

    printf("%d", soma);

    return 0;
    
}

int SomaADP(int N, int m[5][5])
{
    int soma = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j > i)
            soma += m[i][j];
        }
    }
    return soma;
}