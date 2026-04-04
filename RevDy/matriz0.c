#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    int n, m;
    scanf("%d %d", &n, &m);
    int **matriz = (int**)calloc(n, sizeof(int*));

    if (matriz == NULL)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        matriz[i] = (int*)calloc(m, sizeof(int));
    }

    int contador = 1;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matriz[i][j] = contador;
            contador++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
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