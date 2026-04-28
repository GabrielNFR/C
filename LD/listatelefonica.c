#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ListaTelefonica
{
    struct ListaTelefonica *next;
    char *nome;
    char *numTel;
}LT;

LT* createNode(char *nome, char* numTel);
void adicionarContato(LT **head, char *nome, char *numTel);
void excluirContato(LT **head, char *nome, char *numTel);
void removerPorLetra(LT **head, char letra);
LT* buscarContato(LT **head, char *nome, char *numTel);
int contarContatos(LT *head);
void exibirContatos(LT *head);
void liberarMemoria(LT *head);
void atualizarNumero(LT *head, char *nome, char *novoNum);

int main(void)
{   
    LT *head = NULL;

    printf("=== 1. ADICIONANDO CONTATOS (Testando ordem alfabetica) ===\n");
    adicionarContato(&head, "Joao", "8278364783");
    adicionarContato(&head, "Marcos", "999283975");
    adicionarContato(&head, "Ana", "111111111");
    adicionarContato(&head, "Zebra", "222222222");
    adicionarContato(&head, "Maria", "333333333");
    exibirContatos(head);

    printf("\n=== 2. CONTANDO CONTATOS ===\n");
    printf("Total de contatos cadastrados: %d\n", contarContatos(head));

    printf("\n=== 3. BUSCANDO CONTATOS ===\n");
    LT *busca = buscarContato(&head, "Joao", "8278364783");
    if (busca != NULL) {
        printf("Encontrado com sucesso: %s - %s\n", busca->nome, busca->numTel);
    }
    
    printf("Buscando alguem que nao existe: \n");
    buscarContato(&head, "Carlos", "000"); 

    printf("\n=== 4. ATUALIZANDO NUMERO (Ana) ===\n");
    atualizarNumero(head, "Ana", "000000000");
    exibirContatos(head);

    printf("\n=== 5. EXCLUINDO UM CONTATO ESPECIFICO (Joao) ===\n");
    excluirContato(&head, "Joao", "8278364783");
    exibirContatos(head);

    printf("\n=== 6. REMOVENDO POR LETRA INICIAL ('M') ===\n");
    removerPorLetra(&head, 'M'); 
    exibirContatos(head);
    printf("Total de contatos agora: %d\n", contarContatos(head));

    printf("\n=== 7. LIBERANDO MEMORIA ===\n");
    liberarMemoria(head);
    printf("Memoria limpa e programa encerrado com sucesso.\n");

    return 0;
}

LT* createNode(char *nome, char* numTel)
{
    LT *novo = (LT*)malloc(sizeof(LT));

    if (novo == NULL)
    {
        return NULL;
    }

    novo->nome = strdup(nome);
    novo->numTel = strdup(numTel);
    novo->next = NULL;

    return novo;
}

void adicionarContato(LT **head, char *nome, char *numTel)
{
    LT *novo = createNode(nome, numTel);

    if (*head == NULL || strcmp(novo->nome, (*head)->nome) < 0)
    {   
        novo->next = *head;
        *head = novo;
        return;
    }

    LT *atual = *head;
    while (atual->next != NULL && strcmp(atual->next->nome, novo->nome) < 0)
    {
        atual = atual->next;
    }
    novo->next = atual->next;
    atual->next = novo;
}

void excluirContato(LT **head, char *nome, char *numTel)
{
    if (*head == NULL)
    {
        printf("Lista vazia.");
        return;
    }

    LT *atual = *head;
    LT *anterior = NULL;

    while (atual != NULL && (strcmp(atual->nome, nome) != 0 || strcmp(atual->numTel, numTel) != 0))
    {
        anterior = atual;
        atual = atual->next;
    }

    if (atual == NULL)
    {
        printf("Contato não encontrado.\n");
        return;
    }

    if (anterior == NULL)
    {
        *head = atual->next;
    }
    else
    {
        anterior->next = atual->next;
    }

    free(atual->nome);
    free(atual->numTel);
    free(atual);
}

LT* buscarContato(LT **head, char *nome, char *numTel)
{
    LT *atual = *head;

    while (atual != NULL)
    {
        if (strcmp(atual->nome, nome) == 0 && strcmp(atual->numTel, numTel) == 0)
        {
            return atual;
        }

        if (strcmp(atual->nome, nome) > 0)
        {
            printf("Contato não encontrado.\n");
            return NULL;
        }

        atual = atual->next;
    }

    return NULL;
}

void exibirContatos(LT *head)
{
    LT *atual = head;

    while (atual != NULL)
    {
        printf("Nome: %s | Numero: %s\n", atual->nome, atual->numTel);
        atual = atual->next;
    }
}

int contarContatos(LT *head)
{
    LT *atual = head;
    int qtd = 0;

    while (atual != NULL)
    {
        qtd++;
        atual = atual->next;
    }

    return qtd;
}

void atualizarNumero(LT *head, char *nome, char *novoNum)
{
    LT *atual = head;

    while (atual != NULL)
    {
        if (strcmp(atual->nome, nome) == 0)
        {
            free(atual->numTel);
            atual->numTel = strdup(novoNum);
            return;
        }

        atual = atual->next;
    }
}

void removerPorLetra(LT **head, char letra)
{
    LT *atual = *head;

    while (atual != NULL)
    {
        LT *proximo = atual->next;
        
        if (atual->nome[0] == letra)
        {
            excluirContato(head, atual->nome, atual->numTel);
        }
        atual = proximo;
    }
}

void liberarMemoria(LT *head)
{
    while (head != NULL)
    {
        LT *temp = head;
        head = temp->next;

        free(temp->nome);
        free(temp->numTel);
        
        free(temp);
    }
}
