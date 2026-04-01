#include <stdio.h>

void selectionSort(float *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (*(v + j) < *(v + min_idx))
            {
                min_idx = j;
            }
        }

        if (min_idx != i)
        {
            float temp = *(v + i);
            *(v + i) = *(v + min_idx);
            *(v + min_idx) = temp;
        }
    }
}

int main(void)
{   
    int n;
    scanf("%d", &n);

    float v[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%f", v + i);
    }

    selectionSort(v, n);

    for (int i = 0; i < n; i++)
    {
        printf("%f ", *(v + i));
    }

    return 0;
}