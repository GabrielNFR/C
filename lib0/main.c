#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "livro.h"

int main(void)
{   
    int total = 0;
    Livro *v = (Livro*)malloc(MAX * sizeof(Livro));

    Livro l1 = {
        1, "Lord of the Rings: As Duas Torres", "Tolkien", 464
    };

    Livro l2 = {
        2, "Exemplo", "Autor", 300
    };


    inserirLivro(v, l1, &total);
    inserirLivro(v, l2, &total);
    removerLivro(v, 2, &total);

    listarLivros(v, &total);

    free(v);

    return 0;
}inserirLivro(v, l1, &total);