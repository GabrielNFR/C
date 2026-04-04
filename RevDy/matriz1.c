#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    int n, m, i, j;
    scanf("%d %d", &n, &m);

    int **matriz = (int**)calloc(n, sizeof(int*));

    if (matriz == NULL)
    {
        return 1;
    }

    for (i = 0; i < n; i++)
    {          
        matriz[i] = (int*)calloc(m, sizeof(int)); 
    }

    int maior;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &matriz[i][j]);
            if (i == 0 && j == 0)
            {
                maior = matriz[i][j];
            }
            else if (matriz[i][j] > maior)
            {
                maior = matriz[i][j];
            }
        }
    }

    printf("%d", maior);

    for (int i = 0; i < n; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}