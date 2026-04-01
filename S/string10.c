#include <stdio.h>

int palindromoEstrito(char *str)
{
    char *p = str;
    int strLen = 0;

    while (*str != '\0')
    {
        strLen++;
        p++;
        str++;
    }
    str = str - strLen;
    p--;

    while (str < p)
    {
        while (*str == ' ')
        {
            str++;
        }

        while (*p == ' ')
        {
            p--;
        }

        if (str >= p)
        {
            break;
        }
        
        if (*str >= 'A' && *str <= 'Z')
        {
            *str = *str + 32;
        }

        if (*p >= 'A' && *p <= 'Z')
        {
            *p = *p + 32;
        }
        
        if (*str != *p)
        {
            return 0;
        }
        str++;
        p--;
    }
    return 1;
}

int main(void)
{   
    char str[100];
    char *p;

    fgets(str, 100, stdin);
    p = str;

    while (*p != '\0')
    {
        if (*p == '\n')
        {
            *p = '\0';
            break;
        }
        p++;
    }

    int resultado = palindromoEstrito(str);

    printf("%d", resultado);

    return 0;
}