#include <stdio.h>

int compara_sufixo(char *str, char *sufixo)
{
    int len_str = 0;
    int len_suf = 0;

    while (*str != '\0')
    {
        len_str++;
        str++;
    }
    while (*sufixo != '\0')
    {
        len_suf++;
        sufixo++;
    }

    if (len_suf > len_str)
    {
        return 0;
    }

    str = str - len_str;
    sufixo = sufixo - len_suf;

    int saltos = len_str - len_suf;
    while (saltos > 0)
    {
        str++;
        saltos--;
    }

    while (*str != '\0' && *sufixo != '\0')
    {
        if (*str != *sufixo)
        {
            return 0;
        }
        str++;
        sufixo++;
    }
    return 1;
}

int main(void)
{
    char str[100];
    char sufixo[10];
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

    fgets(sufixo, 10, stdin);
    p = sufixo;
    while (*p != '\0')
    {
        if (*p == '\n')
        {
            *p = '\0';
            break;
        }
        p++;
    }

    int resultado = compara_sufixo(str, sufixo);

    printf("%d", resultado);

    return 0;
}