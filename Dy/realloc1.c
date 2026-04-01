#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    int *v;
    int capacidade = 5;
    int quantidade = 0;

    v = (int*)malloc(capacidade * sizeof(int));
    if (v == NULL)
    {
        printf("Erro de alocação.");
        free(v);
        return 1;
    }

    while (1)
    {
        printf("Escreva um valor:\n");

        if (quantidade == capacidade)
        {
            capacidade += 5;
            int *p = realloc(v, capacidade * sizeof(int));
            if (p == NULL)
            {
                printf("Erro de alocação.");
                free(v);
                return 1;
            }
            v = p;
        }

        int lido = scanf("%d", &v[quantidade]);

        if (lido != 1)
        {
            break;
        }

        quantidade++; 

    }

    for (int i = 0; i < quantidade; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    free(v);

    return 0;
}

