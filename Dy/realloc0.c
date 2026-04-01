#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    int *v;
    int i = 0;
    int capacidade = 5;
    int quantidade = 0;
    int temp;

    v = (int*)malloc(capacidade * sizeof(int));

    while (1)
    {
        printf("Escreva um valor (-1 para sair):\n");
        scanf("%d", &temp);

        if (temp == -1)
        {
            break;
        }

        if (quantidade == capacidade)
        {
            capacidade += 5;

            int *tempPtr = realloc(v, capacidade * sizeof(int));
            if (tempPtr == NULL)
            {
                printf("Erro de alocação.");
                free(v);
                return 1;
            }
            v = tempPtr;
        }
        v[quantidade] = temp;
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