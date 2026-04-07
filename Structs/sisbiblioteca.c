#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int ano;
    char titulo[50];
}Livro;

typedef struct
{
    Livro livros[10];
    int quantidadeLivros;
    char nome[50];
}Autor;

Autor autorComLivroMaisRecente(int n, Autor v[n])
{
    int maiorI = 0;
    int maisRecente = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < v[i].quantidadeLivros; j++)
        {
            if (v[i].livros[j].ano > maisRecente)
            {
                maisRecente = v[i].livros[j].ano;
                maiorI = i;
            }
        }
    }

    return v[maiorI];
}

int main(void)
{   
    int n;
    scanf("%d", &n);
    Autor v[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%s", v[i].nome);
        scanf("%d", &v[i].quantidadeLivros);
        for (int j = 0; j < v[i].quantidadeLivros; j++)
        {
            scanf("%s", v[i].livros[j].titulo);
            scanf("%d", &v[i].livros[j].ano);
        }
    }

    Autor a = autorComLivroMaisRecente(n, v);

    printf("\n%s\n", a.nome);

    return 0;
}