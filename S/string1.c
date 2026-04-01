#include <stdio.h>

void conta_caracteres(char *str, int *vogais, int *consoantes)
{
    *vogais = 0;
    *consoantes = 0;
    
    while (*str != '\0')
    {
        if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u')
        {
            (*vogais)++;
        }
        else if (*str >= 'a' && *str <= 'z')
        {
            (*consoantes)++;
        }
        str++;
    }
}

int main(void)
{   
    char str[50];

    int consoantes, vogais;
    fgets(str, 50, stdin);
    conta_caracteres(str, &vogais, &consoantes);
    printf("%sVogais = %d\nConsoantes = %d\n", str, vogais, consoantes); 

    return 0;
}