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

    int *v1;
    v1 = (int*)calloc(n, sizeof(int));

    int j = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        v1[j] = v[i];
        j++;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", v1[i]);
    }

    free(v);
    free(v1);

    return 0;
}