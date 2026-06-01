#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarefas
{
    int id;
    char *descricao;
    int prioridade;
    struct Tarefas *next;
}Tarefas;

void inserir(Tarefas **head, int id, char *descricao, int prioridade)
{
    Tarefas *novo = (Tarefas*)malloc(sizeof(Tarefas));
    novo->descricao = strdup(descricao);
    novo->id = id;
    novo->prioridade = prioridade;

    if (*head == NULL || prioridade < (*head)->prioridade)
    {
        novo->next = *head;
        *head = novo;
        return;
    }

    Tarefas *atual = *head;
    while (atual != NULL && atual->next->prioridade <= prioridade)
    {
        atual = atual->next;    
    }

    novo->next = atual->next;
    atual->next = novo;
}

int main(void)
{   


    return 0;
}