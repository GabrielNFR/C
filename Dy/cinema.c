#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void menu(char ****sala, int *fileiras, int *poltronas);
char*** adicionarFileira(char ***sala, int *fileiras, int poltronas);
void reservarPoltrona(char ***sala, int fileiras, int poltronas);
void cancelarReserva(char ***sala, int fileiras, int poltronas);
void imprimirMapa(char ***sala, int fileiras, int poltronas);
void liberarMemoria(char ***sala, int fileiras, int poltronas);

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);

    char ***sala;
    int fileiras = 2;
    int poltronas = 3;

    sala = (char***)calloc(fileiras, sizeof(char**));

    if (sala == NULL)
    {
        return 1;
    }

    for (int i = 0; i < fileiras; i++)
    {
        sala[i] = (char**)calloc(poltronas, sizeof(char*));

        if (sala[i] == NULL)
        {
            return 1;
        }
    }
    
    menu(&sala, &fileiras, &poltronas);

    return 0;
}

void menu(char ****sala, int *fileiras, int *poltronas)
{
    int opcao;
    
    do {
        printf("\n=================================");
        printf("\nMenu:\n");
        printf("1. Adicionar Fileira\n");
        printf("2. Reservar Poltrona\n");
        printf("3. Cancelar Reserva\n");
        printf("4. Imprimir\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                *sala = adicionarFileira(*sala, fileiras, *poltronas);
                break;
            case 2:
                reservarPoltrona(*sala, *fileiras, *poltronas);
                break;
            case 3:
                cancelarReserva(*sala, *fileiras, *poltronas);
                break;
            case 4:
                imprimirMapa(*sala, *fileiras, *poltronas);
                break;
            case 5:
                liberarMemoria(*sala, *fileiras, *poltronas);
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida.\n");
                break;
        }
    } while (opcao != 5);
}

char*** adicionarFileira(char ***sala, int *fileiras, int poltronas)
{
    (*fileiras)++;
    char ***tempPtr = (char***)realloc(sala, (*fileiras) * sizeof(char**));
    if (tempPtr == NULL)
    {
        (*fileiras)--;
        return sala;
    }
    sala = tempPtr;

    sala[*fileiras - 1] = (char**)calloc(poltronas, sizeof(char*));

    return sala;
}
void reservarPoltrona(char ***sala, int fileiras, int poltronas)
{
    int fileira;
    int poltrona;
    char nome[100];
    
    printf("Digite o número da fileira: ");
    scanf("%d", &fileira);
    if (fileira < 0 || fileira >= fileiras)
    {
        printf("\nFileira inexistente.\n");
        return;
    }

    printf("Digite o número da poltrona: ");
    scanf("%d", &poltrona);
    if (poltrona < 0 || poltrona >= poltronas)
    {
        printf("\nPoltrona inexistente.\n");
        return;
    }

    if (sala[fileira][poltrona] != NULL)
    {
        printf("Poltrona já ocupada.\n");
        return;
    }

    printf("Digite o nome do reservista: ");
    scanf(" %99[^\n]", nome);

    int len = strlen(nome) + 1;

    char *tempPtr = (char*)malloc(len * sizeof(char));
    if (tempPtr == NULL)
    {
        printf("\nMemória cheia.\n");
        return;
    }
    sala[fileira][poltrona] = tempPtr;
    strcpy(sala[fileira][poltrona], nome);
}
void cancelarReserva(char ***sala, int fileiras, int poltronas)
{
    int fileira;
    int poltrona;

    printf("Digite o número da fileira: ");
    scanf("%d", &fileira);
    if (fileira < 0 || fileira >= fileiras)
    {
        printf("\nFileira inexistente.\n");
        return;
    }

    printf("Digite o número da poltrona: ");
    scanf("%d", &poltrona);
    if (poltrona < 0 || poltrona >= poltronas)
    {
        printf("\nPoltrona inexistente.\n");
        return;
    }

    if (sala[fileira][poltrona] == NULL)
    {
        printf("Esta poltrona já está livre.\n");
        return;
    }
    else
    {
        free(sala[fileira][poltrona]);
        sala[fileira][poltrona] = NULL;
        printf("Reserva Cancelada.\n");
    }
}
void imprimirMapa(char ***sala, int fileiras, int poltronas)
{
    printf("Mapa atual: %dx%d\n", fileiras, poltronas);
    for (int i = 0; i < fileiras; i++)
    {
        for (int j = 0; j < poltronas; j++)
        {
            if (sala[i][j] == NULL)
            {
                printf("[LIVRE] ");
            }
            else
            {
            printf("[%s]", sala[i][j]);
            }
        }
        printf("\n");
    }
}
void liberarMemoria(char ***sala, int fileiras, int poltronas)
{
    for (int i = 0; i < fileiras; i++)
    {
        for (int j = 0; j < poltronas; j++)
        {
            if (sala[i][j] != NULL)
            {
                free(sala[i][j]);
            }
        }
        free(sala[i]);
    }
    free(sala);
}