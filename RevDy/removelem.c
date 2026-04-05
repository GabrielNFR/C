#include <stdio.h>
#include <stdlib.h>

int* removerNeg(int *v, int *n)
{
    int N = 0;
    for (int i = 0; i < *n; i++)
    {
        if (v[i] >= 0)
        {
            v[N] = v[i];
            N++;
        }
    }

    if (N == 0)
    {
        free(v);
        *n = 0;
        return NULL;
    }
    
    int *p = (int*)realloc(v, N * sizeof(int));

    if (p != NULL)
    {
        v = p;
    }

    *n = N;

    return v;
}

int main(void)
{   
    int n;
    scanf("%d", &n);

    int *v = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i ++)
    {
        scanf("%d", &v[i]);
    }

    int *vr = removerNeg(v, &n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", vr[i]);
    }
    printf("\n");

    free(vr); 

    return 0;
}