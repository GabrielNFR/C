#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    int n;
    scanf("%d", &n);

    if (n <= 0) 
    {
        return 1;
    }

    float *v;
    float media = 0;

    v = (float*)calloc(n, sizeof(float));

    if (v == NULL)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%f", &v[i]);
    }

    for (int i = 0; i < n; i++)
    {
        media += v[i];
    }
    media = media / n;

    printf("%.2f", media);
    
    free(v);
    
    return 0;
}