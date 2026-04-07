#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    float preco;
    char nome[50];
}Produto;

typedef struct 
{
    Produto itens[5];
    int quantidade;
}Pedido;

float valorTotalPedidos(Pedido p)
{
    float vTotal = 0;
    for (int i = 0; i < 5; i++)
    {
        vTotal += p.itens[i].preco;
    }

    return vTotal;
}

int pedidoMaisCaro(int n, Pedido v[n])
{
    float maiorVT = 0;
    int maiorI;

    for (int i = 0; i < n; i++)
    {
        float totalAtual = valorTotalPedidos(v[i]);
        if (totalAtual > maiorVT)
        {
            maiorVT = totalAtual;
            maiorI = i;
        }
    }

    return maiorI;
}

int main(void)
{   
    int n;
    scanf("%d", &n);

    Pedido v[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i].quantidade);
        for (int j = 0; j < v[i].quantidade; j++)
        {
            scanf("%s", v[i].itens[j].nome);
            scanf("%f", &v[i].itens[j].preco);
        }
    }

    int maisCaro = pedidoMaisCaro(n, v);

    printf("%d", maisCaro);

    return 0;
}