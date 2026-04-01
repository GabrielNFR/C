#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void menu(int ***planilha, int *linhas, int *colunas);
int** adicionarLinha(int **planilha, int *linhas, int colunas);
void adicionarColuna(int **planilha, int linhas, int *colunas);
void editarCelula(int **planilha, int linhas, int colunas);
void imprimir(int **planilha, int linhas, int colunas);
void liberarMemoria(int **planilha, int linhas);

int main(void)
{   
    SetConsoleOutputCP(CP_UTF8);

    int **planilha;
    int linhas = 2;
    int colunas = 2;

    planilha = (int**)calloc(linhas, sizeof(int*));

    if (planilha == NULL)
    {
        return 1;
    }

    for (int i = 0; i < linhas; i++)
    {
        planilha[i] = (int*)calloc(colunas, sizeof(int));

        if (planilha[i] == NULL)
        {
            return 1;
        }
    }    

    menu(&planilha, &linhas, &colunas);

    return 0;
}

void menu(int ***planilha, int *linhas, int *colunas)
{
    int opcao;
    
    do {
        printf("\n=================================");
        printf("\nMenu:\n");
        printf("1. Adicionar Linha\n");
        printf("2. Adicionar Coluna\n");
        printf("3. Editar Célula\n");
        printf("4. Imprimir\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                *planilha = adicionarLinha(*planilha, linhas, *colunas);
                break;
            case 2:
                adicionarColuna(*planilha, *linhas, colunas);
                break;
            case 3:
                editarCelula(*planilha, *linhas, *colunas);
                break;
            case 4:
                imprimir(*planilha, *linhas, *colunas);
                break;
            case 5:
                liberarMemoria(*planilha, *linhas);
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida.\n");
                break;
        }
    } while (opcao != 5);
}

int** adicionarLinha(int **planilha, int *linhas, int colunas)
{
    (*linhas)++;
    int **tempPtr = (int**)realloc(planilha, (*linhas) * sizeof(int*));
    
    if (tempPtr == NULL)
    {
            (*linhas)--;
            return planilha;
    }
    planilha = tempPtr;

    planilha[*linhas - 1] = (int*)calloc(colunas, sizeof(int));

    return planilha;   
}
void adicionarColuna(int **planilha, int linhas, int *colunas)
{
    (*colunas)++;
    for (int i = 0; i < linhas; i++)
    {
        int *tempPtr = (int*)realloc(planilha[i], (*colunas) * sizeof(int));
        if (tempPtr == NULL)
        {
            (*colunas)--;
            return;
        }
        planilha[i] = tempPtr;
        planilha[i][(*colunas) - 1] = 0;
    }
}
void editarCelula(int **planilha, int linhas, int colunas)
{
    int linha;
    int coluna;
    int valor;

    printf("Digite a linha da coordenada a ser modificada: ");
    scanf("%d", &linha);
    if (linha >= linhas || linha < 0)
    {
        printf("Linha inexistente.");
        return;
    }

    printf("\nDigite a coluna da coordenada a ser modificada: ");
    scanf("%d", &coluna);
    if (coluna >= colunas || coluna < 0)
    {
        printf("Coluna inexistente.");
        return;
    }

    printf("\nDigite o valor da célula: ");
    scanf("%d", &valor);

    planilha[linha][coluna] = valor;
}
void imprimir(int **planilha, int linhas, int colunas)
{
    printf("Planilha atual: %dx%d\n", linhas, colunas);
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%4d", planilha[i][j]);
        }
        printf("\n");
    }
}

void liberarMemoria(int **planilha, int linhas)
{
    for (int i = 0; i < linhas; i++)
    {
        free(planilha[i]);
    }
    free(planilha);
}