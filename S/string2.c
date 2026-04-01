#include <stdio.h>

char *cifra_cesar(char *str, int deslocamento)
{
    char *inicio = str;
    
    deslocamento = deslocamento % 26;
    if (deslocamento < 0)
    {
        deslocamento += 26;
    }
    
    while (*str != '\0')
    {
        if (*str >= 'a' && *str <= 'z')
        {
            *str = 'a' + ((*str - 'a' + deslocamento) % 26);
        }
        else if (*str >= 'A' && *str <= 'Z')
        {
            *str = 'A' + ((*str - 'A' + deslocamento) % 26);
        }
        str++;
    } 
    return inicio;
}

int main(void)
{   
    char str[50];
    int deslocamento;

    fgets(str, 50, stdin);
    scanf("%d", &deslocamento);
    
    char *resultado = cifra_cesar(str, deslocamento);

    printf("%s\n", resultado);

    return 0;
}