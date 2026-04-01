#include <stdio.h>

int ehSimetrica(int *m, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (*(m + i * n + j) != *(m + j * n + i))
            {
                return 0;
            }
        }
    }
    return 1;
}

int main(void)
{   
    int n;

    scanf("%d", &n);

    int m[n][n];
    int *p = (int *)m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", p + (i * n + j));
        }
    }

    int resultado = ehSimetrica(*m, n);

    printf("%d", resultado);

    return 0;
}