#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* redimensionar(int *v, int n)
{
    int quantidade = 0;
    
    while (quantidade < n && v[quantidade] != 0)
    {
        quantidade++;
    }
    
    while (1)
    {  

        if (quantidade == n)
        {
            n *= 2;
            int *tempPtr = (int*)realloc(v, n * sizeof(int));
            if (tempPtr == NULL)
            {
                return v;
            }
            v = tempPtr;
        }

        int temp;
        int lido = scanf("%d", &temp);

        if (lido != 1)
        {
            break;
        }

        if (temp != 0)
        {
            v[quantidade] = temp;
            quantidade++;
        }
        else
        {
            for (int i = 0; i < quantidade; i++)
            {
                printf("%d", v[i]);
            }
            printf("\n");
            
            return v;
        }
        
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int *v;
    v = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    v = redimensionar(v, n);

    free(v);
    
    return 0;
}