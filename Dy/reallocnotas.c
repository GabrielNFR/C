#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *notas = NULL;
    int n = 0;
    int capacidade = 0;
    int temp;
    float media = 0;
    int maior = 0;
    int menor = 0;
    int GE_MEDIA = 0;

    notas = (int*)malloc(capacidade * sizeof(int));

    // TODO: Leia inteiros até encontrar -1.
    // Use realloc para aumentar o vetor dinamicamente.
    while (1)
    {
        scanf("%d", &temp);

        if (temp == -1)
        {
            if (n == 0)
            {
                printf("N=%d\n", n);
                printf("MEDIA=%.2f\n", media);
                printf("MAIOR=%d MENOR=%d\n", maior, menor);
                printf("GE_MEDIA=%d", GE_MEDIA);

                return 0;
            }
            break;
        }

        if (n == capacidade)
        {
            capacidade += 1;

            int *tempPtr = realloc(notas, capacidade * sizeof(int));
            if (tempPtr == NULL)
            {
                free(notas);
                return 1;
            }
            notas = tempPtr;
        }
        notas[n] = temp;
        n++;
    }
    
    menor = notas[0];

    for (int i = 0; i < n; i++)
    {
        media += notas[i];
        if (notas[i] > maior)
        {
            maior = notas[i];
        }
        if (notas[i] < menor)
        {
            menor = notas[i];
        }
    }

    media = media / n;

    for (int i = 0; i < n; i++)
    {
        if (notas[i] >= media)
        {
            GE_MEDIA++;
        }
    }
 
    // TODO: Imprima exatamente no formato pedido.
    printf("N=%d\n", n);
    printf("MEDIA=%.2f\n", media);
    printf("MAIOR=%d MENOR=%d\n", maior, menor);
    printf("GE_MEDIA=%d", GE_MEDIA);

    // TODO: Libere a memória com free.
    free(notas);

    return 0;
}
