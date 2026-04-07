#include <stdio.h>
#include <stdlib.h>

typedef struct Funcionario
{
    float salarioBase;
    float bonus;
    char nome[50];
}Funcionario;

int buscarMaiorTotal(int n, Funcionario v[n])
{
    float maiorSalTotal = v[0].salarioBase + v[0].bonus;
    int maiorI = 0;

    for (int i = 0; i < n; i++)
    {
        float salTotal = v[i].salarioBase + v[i].bonus;
        if (salTotal > maiorSalTotal)
        {
            maiorSalTotal = salTotal;
            maiorI = i;
        }
    }

    return maiorI;
}

int main(void)
{   
    int n;
    scanf("%d", &n);

    Funcionario v[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%f", &v[i].salarioBase);
        scanf("%f", &v[i].bonus);
        scanf("%s", v[i].nome);
    }

    int maiorI = buscarMaiorTotal(n, v);

    float salTotal = v[maiorI].salarioBase + v[maiorI].bonus;

    printf("\n%.2f\n", salTotal);
    printf("%s\n", v[maiorI].nome);

    return 0;
}