#include <stdio.h>

int contemSubstring(char *str, char *sub)
{
    int len_sub = 0;

    while (*sub != '\0')
    {
        len_sub++;
        sub++;
    }
    sub = sub - len_sub;

    while (*str != '\0')
    {
        if (*str == *sub)
        {
            int match = 1;
            for (int i = 0; i < len_sub; i++)
            {
                if (*(str + i) != *(sub + i) || *(str + i) == '\0')
                {
                    match = 0;
                    break;
                }
            }
            if (match == 1)
            {
                return 1;
            }
        }
        str++;
    }
    return 0;
}

int main(void)
{   
    char str[100];
    char sub[10];
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
    
    fgets(sub, 100, stdin);
    p = sub;
    while (*p != '\0')
    {
        if (*p == '\n') 
        {
            *p = '\0';
            break;
        }
        p++;
    }

    int resultado = contemSubstring(str, sub);

    printf("%d", resultado);

    return 0;
}