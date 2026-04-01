#include <stdio.h>

int comprimento(char *str)
{
    int comprimento = 0;
    while (*str != '\0' && *str != '\n')
    {
        comprimento++;
        str++;
    }
    return comprimento;
}

int main(void)
{   
    char str[100];
    fgets(str, 100, stdin);

    int comp = comprimento(str);
    printf("Comprimento: %d", comp);

    return 0;
}