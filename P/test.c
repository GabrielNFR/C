#include <stdio.h>

int main(void)
{   
    int idade = 25;
    int *p = &idade;

    printf("%d\n", idade);
    printf("%p\n", p);
    printf("%d\n", *p);

    *p = 26;

    printf("%d\n", idade);

    return 0;
}