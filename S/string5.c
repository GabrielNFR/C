#include <stdio.h>

int extrai_digitos(char *origem, char *destino)
{
    int digitos = 0;

    while (*origem != '\0' && *origem != '\n')
    {
        if (*origem >= '0' && *origem <= '9')
        {
            *destino = *origem;
            destino++;
            digitos++;
        }
        origem++;
    }
    *destino = '\0';

    return digitos;
}

int main(void)
{   
    char origem[100];
    char destino[100];

    fgets(origem, 100, stdin);

    int qtd = extrai_digitos(origem, destino);

    printf("Numeros extraidos: %s\n", destino);
    printf("Quantidade: %d", qtd);

    return 0;
}