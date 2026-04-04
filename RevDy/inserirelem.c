#include <stdio.h>
#include <stdlib.h>

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

    int x, p;

    scanf("%d %d", &x, &p);
    n++;

    if (p < 0 || p > n)
    {
        return 1;
    }

    int *tempPtr = (int*)realloc(v, n * sizeof(int));
    if (tempPtr == NULL);
    {
        free(v);
        return 1;
    }
    v = tempPtr;

    for (int i = n - 1; i > p; i++)
    {
        v[i] = v[i - 1];
    }

    v[p] = x;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    free(v);

    return 0;
}