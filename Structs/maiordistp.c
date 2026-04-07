#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    float x;
    float y;
}Ponto;

float maiorDistancia(int n, Ponto v[n])
{
    float maiorD = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            float atual = sqrt(pow(v[i].x - v[j].x, 2) + pow(v[i].y - v[j].y, 2));
            if (atual > maiorD)
            {
                maiorD = atual;
            }
        }
    }

    return maiorD;
}

int main(void)
{   
    int n;
    scanf("%d", &n);

    Ponto v[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%f %f", &v[i].x, &v[i].y);
    }

    float maiorD = maiorDistancia(n, v);

    printf("%.2f", maiorD);

    return 0;
}

