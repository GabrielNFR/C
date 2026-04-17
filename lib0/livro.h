#define MAX 100

typedef struct
{
    int id;
    char nome[100];
    char autor[100];
    int paginas;
}Livro;

void inserirLivro(Livro v[], Livro novoLivro, int *total);
void removerLivro(Livro v[], int id, int *total);
void listarLivros(Livro v[], int *total);