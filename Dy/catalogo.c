#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void menu();
char** adicionar_livro(char **acervo, int *quantidade, int *capacidade); 
char** remover_livro(char **acervo, int *quantidade, int *capacidade);
void listar_livros(char **acervo, int quantidade, int capacidade);
void liberar_acervo(char **acervo, int quantidade);

int main(void)
{   
    SetConsoleOutputCP(CP_UTF8);

    menu();

    return 0;
}

void menu()
{
    int opcao;
    int capacidade = 2;
    int quantidade = 0;
    char **acervo = (char**)calloc(capacidade, sizeof(char*)); 
    
    do {
        printf("\n=================================");
        printf("\nMenu:\n");
        printf("1. Adicionar Livro\n");
        printf("2. Remover Livro\n");
        printf("3. Listar\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                acervo = adicionar_livro(acervo, &quantidade, &capacidade);
                break;
            case 2:
                acervo = remover_livro(acervo, &quantidade, &capacidade);
                break;
            case 3:
                listar_livros(acervo, quantidade, capacidade);
                break;
            case 4:
                liberar_acervo(acervo, quantidade);
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida.\n");
                break;
        }
    } while (opcao != 4);
}

char** adicionar_livro(char **acervo, int *quantidade, int *capacidade)
{
    char buffer[100];
    printf("Digite o nome do livro a ser adicionado: ");
    scanf(" %99[^\n]", buffer);

    if (*quantidade == *capacidade)
    {
        *capacidade *= 2;

        char **tempPtr = (char**)realloc(acervo, *capacidade * sizeof(char*));
        if (tempPtr == NULL)
        {
            printf("Memória cheia.");

            *capacidade /= 2;
            return acervo;
        }
        acervo = tempPtr;
    }
    int len = strlen(buffer) + 1;

    acervo[*quantidade] = (char*)malloc(len * sizeof(char));
    strcpy(acervo[*quantidade], buffer);
    (*quantidade)++;

    return acervo;
}

char** remover_livro(char **acervo, int *quantidade, int *capacidade)
{
    char buffer[100];
    printf("Adicione o nome do livro a ser removido: ");
    scanf(" %99[^\n]", buffer);

    int encontrado = 0;

    for (int i = 0; i < *quantidade; i++)
    {
        if (strcmp(acervo[i], buffer) == 0)
        {
            free(acervo[i]);
            for (int j = i; j < *quantidade - 1; j++)
            {
                acervo[j] = acervo[j + 1];
            }
            (*quantidade)--;
            encontrado = 1;
            break;
        }
    }
    
    if (encontrado == 0)
        {
            printf("\nLivro não encontrado.");
        }

    if (*quantidade < *capacidade / 2 && *capacidade > 2)
    {
        *capacidade /= 2;

        char **tempPtr = (char**)realloc(acervo, *capacidade * sizeof(char*));
        if (tempPtr == NULL)
        {
            *capacidade *= 2;
            return acervo;
        }
        acervo = tempPtr;
    }

    return acervo;
}
void listar_livros(char **acervo, int quantidade, int capacidade)
{
    if (quantidade == 0)
    {
        printf("Acervo vazio.");
        return;
    }

    printf("Acervo: %d/%d\n", quantidade, capacidade);

    for (int i = 0; i < quantidade; i++)
    {
        printf("%d. %s\n", i + 1, acervo[i]);
    }
}
void liberar_acervo(char **acervo, int quantidade)
{
    for (int i = 0; i < quantidade; i++)
    {
        free(acervo[i]);
    }
    free(acervo);
}