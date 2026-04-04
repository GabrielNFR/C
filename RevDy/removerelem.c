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

    int x;
    scanf("%d", &x);

    int pos = -1;
    
    for (int i = 0; i < n; i++)
    {
        if (v[i] == x)
        {
            pos = i;
            break;
        }
    }

    if (pos != -1)
    {
        for (int i = pos; i < n - 1; i++)
        {
            v[i] = v[i + 1];
        }

        n--;

        if (n > 0)
        {    
            int *tempPtr = (int*)realloc(v, n * sizeof(int));
            if (tempPtr == NULL)
            {
                free(v);
                return 1;
            }
            v = tempPtr;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    free(v);

    return 0;
}