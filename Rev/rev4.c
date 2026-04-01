#include <stdio.h>

void intercala(float *a, float *b, float *resultado, int n)
{
    for (int i = 0; i < n; i++)
    {
        *resultado = *(a + i);
        resultado++;
        *resultado = *(b + i);
        resultado++;
    }
}

int main(void)
{   
    int n;
    scanf("%d", &n);

    float a[n];
    float b[n];
    int k = 2 * n;
    float resultado[k];

    printf("Vetor a:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", a + i);
    }

    printf("Vetor b:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", b + i);
    }

    intercala(a, b, resultado, n);

    printf("Vetor res:\n");
    for (int i = 0; i < k; i++)
    {
        printf("%f ", *(resultado + i));
    }

    return 0;
}