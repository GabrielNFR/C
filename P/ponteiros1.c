#include <stdio.h>

void classificar(int n, int *v, int *positivos, int *negativos, int *zeros)
{
    *positivos = 0;
    *negativos = 0;
    *zeros = 0;

    for (int i = 0; i < n; i++)
    {
        if(*(v + i) > 0)
        {
            (*positivos)++;
        }
        else if (*(v + i) < 0)
        {
            (*negativos)++;
        }
        else
        {
            (*zeros)++;
        }
    }
}

int main(void)
{   
    int n;
    scanf("%d", &n);
    int v[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", v + i);
    }

    int p, neg, z;

    classificar(n, v, &p, &neg, &z);

    printf("P: %d\nN: %d\nZ: %d\n", p, neg, z);

    return 0;
}