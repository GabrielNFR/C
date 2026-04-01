#include <stdio.h>

void estatisticas(float *temp, int n, float *media, float *maior, float *menor)
{
    *maior = temp[0];
    *menor = temp[0];
    float soma = temp[0];

    for (int i = 1; i < n; i++)
    {
        if (*(temp + i) > *maior)
        {
            *maior = *(temp + i);
        }

        if (*(temp + i) < *menor)
        {
            *menor = *(temp + i);
        }

        soma += *(temp + i);
    }

    *media = soma / n;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    
    float temp[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%f", temp + i);
    }

    float media, maior, menor;

    estatisticas(temp, n, &media, &maior, &menor);

    printf("Media: %f\nMaior: %f\nMenor: %f\n", media, maior, menor);

    return 0;
}