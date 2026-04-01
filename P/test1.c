#include <stdio.h>

void swap(int *pA, int *pB)
{
    int aux = *pA;
    *pA = *pB;
    *pB = aux;
}

int main(void)
{   
    int a = 10;
    int b = 20;

    printf("%d\n%d\n", a, b);

    swap(&a, &b);

    printf("%d\n%d\n", a, b);

    return 0;
}