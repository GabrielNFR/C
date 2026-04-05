#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{   
    int n, m;
    scanf("%d %d", &n, &m);

    srand(time(NULL));

    int **matriz = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++)
    {
        matriz[i] = (int*)malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matriz[i][j] = rand() % 100;
        }
    }

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}