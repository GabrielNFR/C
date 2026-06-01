#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
    struct Node *next;
    int valor;
}Node;

void inicializaLista(Node **head)
{
    *head = NULL;
}

void adicionaInicio(Node **head, int valor)
{
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->next = *head;
    *head = novo;
}

void adicionaFinal(Node **head, int valor)
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
    while (atual->next != NULL)
    {
        atual = atual->next;
    }

    atual->next = novo;
}

void removePrimeiro(Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    Node *temp = *head;
    *head = temp->next;
    free(temp);
}

void removeUltimo(Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    Node *atual = *head;
    while (atual->next->next != NULL)
    {
        atual = atual->next;
    }

    free(atual->next);
    atual->next = NULL;
}

void removeValor(Node **head, int valor)
{
    if (*head == NULL)
    {
        return;
    }

    if ((*head)->valor == valor)
    {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node *atual = (*head)->next;
    Node *anterior = *head;
    while (atual != NULL)
    {
        if (atual->valor == valor)
        {
            anterior->next = atual->next;
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->next;
    }
}

void exibeLista(Node *head)
{
    Node *atual = head;
    while (atual != NULL)
    {
        printf("%d\n", atual->valor);
        atual = atual->next;
    }
}

void inverteLista(Node **head)
{
    Node *anterior = NULL;
    Node *atual = *head;
    Node *proximo;

    while (atual != NULL)
    {
        proximo = atual->next;
        atual->next = anterior;
        anterior = atual;
        atual = proximo;
    }
    *head = anterior;
}

void ordenarLista(Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    
    Node *atual = *head;
    Node *seguinte = NULL;
    int temp;

    while (atual != NULL)
    {
        seguinte = atual->next;

        while (seguinte != NULL)
        {
            if (atual->valor > seguinte->valor)
            {
                temp = atual->valor;
                atual->valor = seguinte->valor;
                seguinte->valor = temp;
            }

            seguinte = seguinte->next;
        }

        atual = atual->next;
    } 
}

int contaNos(Node *head)
{
    int n = 0;
    Node *atual = head;
    while (atual != NULL)
    {
        n++;
        atual = atual->next;
    }

    return n;
}

int temCiclo(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    
    Node *unico = head;
    Node *duplo = head;

    while (duplo != NULL && duplo->next != NULL)
    {
        unico = unico->next;
        duplo = duplo->next->next;

        if (duplo == unico)
        {
            return 1;
        }
    }

    return 0;
}

Node* copiaLista(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    
    Node *novoHead = (Node*)malloc(sizeof(Node));
    novoHead->valor = head->valor;
    novoHead->next = NULL;

    Node *atualOriginal = head->next;
    Node *atualCopia = novoHead;

    while (atualOriginal != NULL)
    {
        Node *novoNode = (Node*)malloc(sizeof(Node));
        novoNode->valor = atualOriginal->valor;
        novoNode->next = NULL;

        atualCopia->next = novoNode;
        atualCopia = atualCopia->next;
        atualOriginal = atualOriginal->next;
    }

    return novoHead;
}

Node* busca(Node *head, int valor)
{
    Node *atual = head;
    while (atual != NULL)
    {
        if (atual->valor == valor)
        {
            return atual;
        }
        atual = atual->next;
    }

    return NULL;
}

Node* encontraMeio(Node *head)
{
    Node *unico = head;
    Node *duplo = head;

    while (duplo != NULL && duplo->next != NULL)
    {
        unico = unico->next;
        duplo = duplo->next->next;
    }

    return unico;
}

int maiorValor(Node *head)
{
    if (head == NULL)
    {
        return INT_MIN;
    }

    int maior = head->valor;
    Node *atual = head->next;
    while (atual != NULL)
    {
        if (atual->valor > maior)
        {
            maior = atual->valor;
        }
        atual = atual->next;
    }

    return maior;
}

void liberaLista(Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    Node *proximo;
    Node *atual = *head;
    while (atual != NULL)
    {
        proximo = atual->next;
        free(atual);
        atual = proximo;
    }

    *head = NULL;
}

int main(void)
{   
    Node *lista;
    inicializaLista(&lista);

    return 0;
}

