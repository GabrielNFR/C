#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{   
    char **listaConvidados;
    int capacidade = 2;
    int quantidade = 0;

    listaConvidados = (char**)malloc(capacidade * sizeof(char*));
    char buffer[100];

    while (1)
    {
        printf("Digite um nome: ");
        scanf(" %99[^\n]", buffer);

        if (strcmp(buffer, "SAIR") == 0)
        {
            if (quantidade == 0)
            {
                free(listaConvidados);
                return 0;
            }
            break;
        }

        if (quantidade == capacidade)
        {
            capacidade += 2;

            char **tempPtr = (char**)realloc(listaConvidados, capacidade * sizeof(char*));
            if (tempPtr == NULL)
            {
                for (int i = 0; i < quantidade; i++)
                {
                    free(listaConvidados[i]);
                }
                free(listaConvidados);
                return 1;
            }
            listaConvidados = tempPtr;
        }
        int len = strlen(buffer) + 1;

        listaConvidados[quantidade] = (char*)malloc(len * sizeof(char));

        strcpy(listaConvidados[quantidade], buffer);
        quantidade++;
    }

    for (int i = 0; i < quantidade; i++)
    {
        printf("%s\n", listaConvidados[i]);
    }
    printf("\n");

    for (int i = 0; i < quantidade; i++)
    {
        free(listaConvidados[i]);
    }

    free(listaConvidados);

    return 0;
}