#include <stdio.h>
#include <stdlib.h>

int* concatenar(int *v0, int n0, int *v1, int n1)
{
    int *v2;
    int len = n0 + n1;

    v2 = (int*)calloc(len, sizeof(int));

    for (int i = 0; i < n0; i++)
    {
        v2[i] = v0[i];
    }

    for (int i = n0; i < len; i++)
    {
        v2[i] = v1[i - n0];
    }
    
    return v2;    
}

int main(void)
{   
    int n0;
    scanf("%d", &n0);
    int *v0;
    v0 = (int*)calloc(n0, sizeof(int));
    for (int i = 0; i < n0; i++)
    {
        scanf("%d", &v0[i]);
    }
    
    int n1;
    scanf("%d", &n1);
    int *v1;
    v1 = (int*)calloc(n1, sizeof(int));
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &v1[i]);
    }

    int *v2 = concatenar(v0, n0, v1, n1);

    int len = n0 + n1;
    for (int i = 0; i < len; i++)
    {
        printf("%d ", v2[i]);
    }
    printf("\n");

    free(v0);
    free(v1);
    free(v2);

    return 0;
}