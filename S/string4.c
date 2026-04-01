#include <stdio.h>

void paraMaiusculas(char *str)
{
    while (*str != '\0' && *str != '\n')
    {
        if (*str >= 'a' && *str <= 'z')
        {
            *str = *str - 32;
        }
        str++;
    }
}

int main(void)
{   
    char str[100];
    fgets(str, 100, stdin);

    printf("Antes: %s", str);

    paraMaiusculas(str);

    printf("Depois: %s", str);

    return 0;
}