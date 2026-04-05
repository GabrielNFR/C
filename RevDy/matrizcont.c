#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    int n, m;
    scanf("%d %d", &n, &m);

    // int (*matriz)[m] = (int (*)[m])calloc(n, sizeof(*matriz));

    int *matriz = (int*)calloc(n * m, sizeof(int));

    if (matriz == NULL) return 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matriz[i * m + j]);
        }
    }

    int soma = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matriz[i * m + j]);
            soma += matriz[i * m + j];
        }
        printf("\n");
    }
    printf("\n");

    printf("%d\n", soma);

    free(matriz);

    return 0;
}