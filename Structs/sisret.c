#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct 
{
    float x;
    float y;
}Ponto;

typedef struct
{
    Ponto p1;
    Ponto p2;
}Ret;

float areaRet(Ret r)
{
    float base = fabs(r.p1.x - r.p2.x);
    float altura = fabs(r.p1.y - r.p2.y);
    return base * altura;
}

int contarRetMaiores(int n, Ret v[n], float valor)
{
    int maiores = 0;
    for (int i = 0; i < n; i++)
    {
        float area = areaRet(v[i]);
        printf("Area do retangulo %d foi: %f\n", i, area);
        if (area > valor)
        {
            maiores++;
        }
    }

    return maiores;
}

int main(void)
{   
    int n;
    scanf("%d", &n);

    Ret r[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%f %f", &r[i].p1.x, &r[i].p1.y);
        scanf("%f %f", &r[i].p2.x, &r[i].p2.y);

        printf("Lido Retangulo %d: p1(%.1f, %.1f) e p2(%.1f, %.1f)\n", i, r[i].p1.x, r[i].p1.y, r[i].p2.x, r[i].p2.y);
    }

    float valor = 10.5;

    int maiores = contarRetMaiores(n, r, valor);

    printf("\n%d\n", maiores);

    return 0;
}
