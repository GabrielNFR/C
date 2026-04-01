#include <stdio.h>

int substituirForaDoIntervalo(float *pesos, int n, float minimo, float maximo, float substituto)
{
    int qtdSub = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(pesos + i) > maximo || *(pesos + i) < minimo)
        {
            *(pesos + i) = substituto;
            qtdSub++;
        }
    }
    return qtdSub;
}

int main(void)
{
    int n;
    float minimo, maximo, substituto;
    scanf("%d", &n);
    scanf("%f", &minimo);
    scanf("%f", &maximo);
    scanf("%f", &substituto);

    float pesos[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%f", pesos + i);
    }

    int subs = substituirForaDoIntervalo(pesos, n, minimo, maximo, substituto);
    printf("Subs: %d", subs);

    return 0;
}