#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int valor;
    struct Node *next;
}Node;

void adicionarInicio(Node **head, int valor)
{
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->next = *head;
    *head = novo;
}

void adicionarFinal(Node **head, int valor)
{
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->next = NULL;

    if (*head == NULL)
    {
       *head = novo;
       return;
    }

    Node *atual = *head;
    while  (atual->next != NULL)
    {
        atual = atual->next;
    }

    atual->next = novo;
}

void removerRepetido(Node **head, int valor)
{
    Node *atual = *head;
    Node *anterior = NULL;
    int encontrou = 0;

    while (atual != NULL)
    {
        if (valor == atual->valor)
        {
            if (encontrou)
            {
                anterior->next = atual->next;
                free(atual);
                atual = anterior->next;
            }
            else
            {
                encontrou = 1;
                anterior = atual;
                atual = atual->next;
            }
        }
        else
        {
            anterior = atual;
            atual = atual->next;
        }
    }
}

void exibirLista(Node *head)
{
    Node *atual = head;
    printf("\nLista atual:\n");
    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->next;
    }
    printf("\n");
}

int main(void)
{   
    Node *lista = NULL;
    
    int opt;
    int valor;
    while (1) 
    {
        printf("Escolha se vai inserir no inicio ou final (I ou F. T para sair)\n");

        scanf(" %c", &opt);

        if (opt == 'I' || opt == 'i')
        {
            printf("Escolha o valor a ser inserido:\n");
            scanf("%d", &valor);
            adicionarInicio(&lista, valor);
            removerRepetido(&lista, valor);
            exibirLista(lista);
        }
        else if (opt == 'F' || opt == 'f')
        {
            printf("Escolha o valor a ser inserido:\n");
            scanf("%d", &valor);
            adicionarFinal(&lista, valor);
            removerRepetido(&lista, valor);
            exibirLista(lista);
        }
        else if (opt == 'T' || opt == 't')
        {
            printf("Saindo...\n");
            return 0;
        }
    }
}