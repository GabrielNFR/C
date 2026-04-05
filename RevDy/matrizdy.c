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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    int soma = 0;
    
    for (int i = 0; i < n; i++)
    {
        soma = 0;
        for (int j = 0; j < m; j++)
        {
            soma += matriz[i][j];
        }
        printf("%d ", soma);
    }
    
    for (int i = 0; i < n; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}