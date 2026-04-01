#include <stdio.h>

void imprimirMatriz(int (*m)[3])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d", m[i][j]);
        }
    }
}

int main(void)
{
    int m[2][3] = {{1, 2, 3},
                   {3, 2, 1}};

    imprimirMatriz(m);

    return 0;
}