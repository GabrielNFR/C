#include <stdio.h>
#include <stdlib.h>

typedef struct Produto
{
    float preco;
    int quantidade;
    char nome[50];
}Produto;

int buscarProdutoMaisCaro(int n, Produto p[n])
{
    float maior = 0;
    int maiorI = 0;

    for (int i = 0; i < n; i++)
    {
        if (p[i].preco > maior)
        {
            maior = p[i].preco;
            maiorI = i;
        }
    }

    return maiorI;
}

int main(void)
{   
    int n;
    scanf("%d", &n);

    Produto p[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%f", &p[i].preco);
        scanf("%d", &p[i].quantidade);
        scanf("%s", p[i].nome);
    }

    int maiorI = buscarProdutoMaisCaro(n, p);

    printf("\n%f\n", p[maiorI].preco);
    printf("%d\n", p[maiorI].quantidade);
    printf("%s\n", p[maiorI].nome);

    return 0;
}