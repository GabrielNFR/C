#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node* criar_no(int value) {
    Node *novo = malloc(sizeof(Node));

    if (novo == NULL) {
        return NULL;
    }

    novo->value = value;
    novo->next = NULL;
    return novo;
}

Node* inserir_fim(Node *head, int value) {
    Node *novo = criar_no(value);

    if (novo == NULL) {
        return head;
    }

    if (head == NULL) {
        return novo;
    }

    Node *atual = head;

    while (atual->next != NULL) {
        atual = atual->next;
    }

    atual->next = novo;
    return head;
}

void imprimir_lista(Node *head) {
    Node *atual = head;

    while (atual != NULL) {
        printf("%d ", atual->value);
        atual = atual->next;
    }

    printf("\n");
}

void liberar_lista(Node *head) {
    Node *atual = head;

    while (atual != NULL) {
        Node *proximo = atual->next;
        free(atual);
        atual = proximo;
    }
}

Node* remover_repetidos_consecutivos(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *atual = head;
    while (atual != NULL && atual->next != NULL)
    {
        if (atual->value == atual->next->value)
        {    
            Node *temp = atual->next;
            atual->next = temp->next;
            free(temp);
        }
        else
        {
            atual = atual->next;
        }
    }

    return head;
}

int main(void) {
    Node *lista = NULL;
    int n;
    int value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        lista = inserir_fim(lista, value);
    }

    lista = remover_repetidos_consecutivos(lista);

    imprimir_lista(lista);

    liberar_lista(lista);

    return 0;
}
