#include <stdio.h>

int maior(int v[], int tamanho);

int main(void)
{
    int v[4] = {4, 7, 3, 10};

    int resultado = maior(v, 4);

    printf("%d\n", resultado);
    
    return 0;
}

int maior(int v[], int tamanho)
{
    if (tamanho < 2) return 0;

    int conta = 0;
    int soma = 0;

    for (int i = 1; i < tamanho; i++)
    {
        soma += v[i-1];
        float media = soma / (float)i;

        if (v[i] > media)
        {
            conta++;
        }
    }

    return conta;
}