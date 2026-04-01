#include <stdio.h>

int qtdPares(int V[], int N);

int main(void)
{
    int V[5] = {1, 3, 2, 7, 4};

    int resultado = qtdPares(V, 5);

    printf("Pares: %d", resultado);

    return 0;
}

int qtdPares(int V[], int N)
{
    int pares = 0;
    for (int i = 0; i < 5; i++)
    {
        if (V[i] % 2 == 0)
        {
            pares++;
        }
    }
    return pares;
}