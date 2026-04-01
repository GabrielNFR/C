#include <stdio.h>

void concatenar(char *str1, char *str2)
{

    while (*str1 != '\0')
    {
        str1++;
    }

    while (*str2 != '\0')
    {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}

int main(void)
{   
    char str1[201];
    char str2[100];
    char *p;

    fgets(str1, 100, stdin);
    p = str1;

    while (*p != '\0')
    {
        if (*p == '\n')
        {
            *p = '\0';
            break;
        }
        p++;
    }

    fgets(str2, 100, stdin);
    p = str2;
    while (*p != '\0')
    {
        if (*p == '\n')
        {
            *p = '\0';
            break;
        }
        p++;
    }

    concatenar(str1, str2);

    printf("%s\n", str1);

    return 0;
}