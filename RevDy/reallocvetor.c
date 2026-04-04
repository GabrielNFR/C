#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    int n = 5;
    int *v;
    int quantidade = 0;

    v = (int*)calloc(n, sizeof(int));

    while (1)
    {
        if (quantidade == 10)
        {
            break;
        }
        
        printf("Digite um int:\n");

        if (quantidade == n)
        {
            n += 5;
            int *tempPtr = (int*)realloc(v, n * sizeof(int));
            if (tempPtr == NULL)
            {
                free(v);
                return 1;
            }
            v = tempPtr;

        }

        int lido = scanf("%d", &v[quantidade]);

        if (lido != 1)
        {
            break;
        }

        quantidade++;

    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    free(v);

    return 0;
}