#include <stdio.h>

void separaTransacoes(float *valores, int n, float *positivos, int *qtdPos, float *negativos, int *qtdNeg)
{
    *qtdPos = 0;
    *qtdNeg = 0;

    for (int i = 0; i < n; i++)
    {
        if (*(valores + i) > 0)
        {
            *positivos = *(valores + i);
            positivos++;
            (*qtdPos)++;
        }
        else if (*(valores + i) < 0)
        {
            *negativos = *(valores + i);
            negativos++;
            (*qtdNeg)++;
        }
    }
}

int main(void)
{   
    int qtdPos;
    int qtdNeg;
    
    int n;
    scanf("%d", &n);
    
    float valores[n];
    for (int i = 0; i< n; i++)
    {
        scanf("%f", valores + i);
    }

    float negativos[n];
    float positivos[n];

    separaTransacoes(valores, n, positivos, &qtdPos, negativos, &qtdNeg);
    printf("Positivos: ");
    for (int i = 0; i < qtdPos; i++)
    {
        printf("%.2f ", *(positivos + i));
    }
    printf("\n");
    printf("qtdPos: %d", qtdPos);
    printf("\n");

    printf("Negativos: ");
    for (int i = 0; i < qtdNeg; i++)
    {
        printf("%.2f ", *(negativos + i));
    }
    printf("\n");
    printf("qtdNeg: %d", qtdNeg);

    return 0;
}