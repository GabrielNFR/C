#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    int n;
    scanf("%d", &n);

    int *v1;
    int *v2;

    v1 = (int*)calloc(n, sizeof(int));
    v2 = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v1[i]);
        v2[i] = v1[i];
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", v2[i]);
    }

    free(v1);
    free(v2);

    return 0;
}