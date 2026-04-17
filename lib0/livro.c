#include <stdio.h>
#include "livro.h"

void inserirLivro(Livro v[], Livro novoLivro, int *total)
{
    if (*total >= MAX)
    {
        printf("Lista cheia.");
        return;
    }
    
    for (int i = 0; i < *total; i++)
    {
        if (v[i].id > novoLivro.id)
        {
            for (int j = *total - 1; j >= i; j--)
            {
                v[j + 1] = v[j];
            }

            v[i] = novoLivro;
            (*total)++;
            return;
        }    
    }
    v[*total] = novoLivro;
    (*total)++;
}

void removerLivro(Livro v[], int id, int *total)
{
    for (int i = 0; i < *total; i++)
    {
        if (v[i].id == id)
        {
            for (int j = i; j < *total - 1; j++)
            {
                v[j] = v[j + 1];
            }
            (*total)--;
            return;
        }
    }
}

void listarLivros(Livro v[], int *total)
{
    if (*total == 0)
    {
        printf("Lista vazia\n");
        return;
    }

    for (int i = 0; i < *total; i++)
    {
        printf("Livro %d: ID: %d | Nome: %s | Autor: %s | Paginas %d |\n", i + 1, v[i].id, v[i].nome, v[i].autor, v[i].paginas);
    }
}