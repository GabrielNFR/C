#include <stdio.h>

void MultiplicarElementos(int M[3][3], int *prin, int *sec, int *col);

int main(void)
{
    int M[3][3] =  {{1, 2, 3},
                    {3, 2, 1},
                    {2, 1, 3}};
    
    int multPrincipal = 1;
    int multSecundaria = 1;
    int multColunaCentral = 1;

    MultiplicarElementos(M, &multPrincipal, &multSecundaria, &multColunaCentral);

    printf("%d, %d, %d", multPrincipal, multSecundaria, multColunaCentral);

    return 0;
}

void MultiplicarElementos(int M[3][3], int *prin, int *sec, int *col)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                *prin *= M[i][j];
            }
            if (i + j == 2)
            {
                *sec *= M[i][j];
            }
            if (j == 1)
            {
                *col *= M[i][j];
            }

        }
    }
}