#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* gerarCracha(char *nome, int nivel)
{
    char prefixo[11];
    if (nivel == 0)
    {
        strcpy(prefixo, "[DEFAULT] ");
    }
    else 
    {
        strcpy(prefixo, "[VIP] ");
    }
    
    int len = (strlen(nome) + strlen(prefixo) + 1);
    char *cracha = (char*)malloc(len * sizeof(char));

    strcpy(cracha, prefixo);
    strcat(cracha, nome);
    
    return cracha;
}

int main(void)
{   
    int capacidade = 3;
    int quantidade = 0;
    char *cracha;

    char **listaCrachas = (char**)calloc(capacidade, sizeof(char*));
    char buffer[100];
    int nivel;

    while(1)
    {
        printf("Digite o nome do cracha: ");
        scanf(" %99[^\n]", buffer);

        if (strcmp(buffer, "SAIR") == 0)
        {
            if (quantidade == 0)
            {
                free(listaCrachas);
                return 0;
            }
            break;
        }
        
        while (1)
        {
            printf("Defina o nivel do cracha (0: [DEFAULT] ou 1: [VIP]): ");
            scanf("%d", &nivel);

            if (nivel == 0 || nivel == 1) {
                break; 
            }
            
            printf("Entrada invalida.\n\n");
        }

        if (quantidade == capacidade)
        {
            capacidade *= 2;

            char **tempPtr = (char**)realloc(listaCrachas, capacidade * sizeof(char*));
            if (tempPtr == NULL)
            {
                for (int i = 0; i < quantidade; i++)
                {
                    free(listaCrachas[i]);
                }
                free(listaCrachas);
                return 1;
            }
            listaCrachas = tempPtr;
        }

        listaCrachas[quantidade] = gerarCracha(buffer, nivel);

        quantidade++;
    }

    for (int i = 0; i < quantidade; i++)
    {
        printf("%s\n", listaCrachas[i]);
    }
    printf("\n");

    for (int i = 0; i < quantidade; i++)
    {
        free(listaCrachas[i]);
    }
    
    free(listaCrachas);

    return 0;
}