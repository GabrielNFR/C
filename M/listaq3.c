#include <stdio.h>

int ordemUnica(int v[], int tamanho, int r[]);

int main(void)
{
    int v[9] = {5, 5, 5, 2, 2, 7, 3, 3, 1};

    int r[9];

    int novoTamanho = ordemUnica(v, 9, r);

    for (int i = 0; i < novoTamanho; i++)
    {
        printf("%d\n", r[i]);
    }
    
    return 0;
}

int ordemUnica(int v[], int tamanho, int r[])
{
    if (tamanho == 0) return 0;

    r[0] = v[0];
    int j = 1;

    for (int i = 1; i < tamanho; i++)
    {
        if (v[i] != v[i - 1])
        {
            r[j] = v[i];
            j++;
        }
    }

    return j;
}