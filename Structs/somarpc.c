#include <stdio.h>
#include <stdlib.h>

typedef struct Ponto
{
    int x;
    int y;
}Ponto;

Ponto somarPontos(Ponto a, Ponto b)
{
    int x = a.x + b.x;
    int y = a.y + b.y;

    Ponto p;
    p.x = x;
    p.y = y;

    return p;
} 

int main(void)
{   
    Ponto p0;
    scanf("%d %d", &p0.x, &p0.y);

    Ponto p1;
    scanf("%d %d", &p1.x, &p1.y);

    Ponto p = somarPontos(p0, p1);

    printf("x = %d, y = %d", p.x, p.y);

    return 0;
}