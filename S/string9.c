#include <stdio.h>

int removeOcorrencias(char *str, char alvo)
{
    int removidos = 0;
    char *p = str;

    while (*str != '\0')
    {
        if (*str != alvo)
        {   
            *p = *str;
            p++;
        }
        else
        {
            removidos++;
        }
        str++;
    }
    *p = '\0';

    return removidos;
}

int main(void)
{
    char str[100];
    char alvo;
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

    scanf("%c", &alvo);

    printf("%s\n", str);
    int removidos = removeOcorrencias(str, alvo);
    printf("%s Removidos: %d\n", str, removidos);

    return 0;
}