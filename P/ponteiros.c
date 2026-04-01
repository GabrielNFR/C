// Online C compiler to run C program online
#include <stdio.h>

int produtoEscalar(int *v1, int *v2, int n)
{
    int soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma += *(v1 + i) * *(v2 + i);
    }
    return soma;
}

int main() {
    int n;
    scanf("%d", &n);
    int v1[n];
    int v2[n];
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", v1 + i);
    }
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", v2 + i);
    }
    
    int produto = produtoEscalar(v1, v2, n);
    printf("%d", produto);

    return 0;
}