#include <stdio.h>
#include <stdlib.h>

int main(void)
{       
    int n;
    float *v;
    scanf("%d", &n);

    v = (float*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", v[i]);
    }
    printf("\n");

    int dia;

    while (1)
    {
        printf("Escolha o dia para registrar as vendas (-1 para sair):\n");
        scanf("%d", &dia);

        if (dia == -1)
        {
            break;
        }
        
        printf("Valor das vendas:\n");
        scanf("%f", &v[dia]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", v[i]);
    }
    printf("\n");

    free(v);

    return 0;
}