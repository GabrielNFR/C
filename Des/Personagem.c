#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Personagem
{
    char *nome;
    int vida;
    int ataque;
    int defesa;
    int qtdItens;
    char **itens;
    int *vQtdItens;
}Personagem;

Personagem* substituirPersonagem(Personagem *pIn, Personagem *pOut, int n, int pos, char *nome, int vida, int ataque, int defesa, char **itens, int *vQtdItens, int qtdItens)
{
    for (int i = 0; i < n; i++)
    {
        if (i == pos)
        {
            pOut[i].nome = (char*)calloc(strlen(nome) + 1, sizeof(char));
            strcpy(pOut[i].nome, nome);

            if (qtdItens > 0)
            {
                pOut[i].itens = (char**)calloc(1, sizeof(char*));
                pOut[i].vQtdItens = (int*)calloc(1, sizeof(int));

                for (int j = 0; j < qtdItens; j++)
                {
                    pOut[i].itens[j] = (char*)calloc(strlen(itens[j]) + 1, sizeof(char));
                    strcpy(pOut[i].itens[j], itens[j]);

                    pOut[i].vQtdItens[j] = vQtdItens[j];

                    if (j < qtdItens - 1)
                    {
                        pOut[i].itens = (char**)realloc(pOut[i].itens, (j + 2) * sizeof(char*));
                        pOut[i].vQtdItens = (int*)realloc(pOut[i].vQtdItens, (j + 2) * sizeof(int));
                    }
                }
            }
            else if (qtdItens == 0)
            {
                pOut[i].itens = NULL;
                pOut[i].vQtdItens = NULL;
            }

            pOut[i].vida = vida;
            pOut[i].ataque = ataque;
            pOut[i].defesa = defesa;
            pOut[i].qtdItens = qtdItens;
        }
        else
        {
            pOut[i].nome = (char*)calloc(strlen(pIn[i].nome) + 1, sizeof(char));
            strcpy(pOut[i].nome, pIn[i].nome);

            if (pIn[i].qtdItens > 0)
            {
                pOut[i].itens = (char**)calloc(1, sizeof(char*));
                pOut[i].vQtdItens = (int*)calloc(1, sizeof(int));

                for (int j = 0; j < pIn[i].qtdItens; j++)
                {
                    pOut[i].itens[j] = (char*)calloc(strlen(pIn[i].itens[j]) + 1, sizeof(char));
                    strcpy(pOut[i].itens[j], pIn[i].itens[j]);

                    pOut[i].vQtdItens[j] = pIn[i].vQtdItens[j];

                    if (j < pIn[i].qtdItens - 1)
                    {
                        pOut[i].itens = (char**)realloc(pOut[i].itens, (j + 2) * sizeof(char*));
                        pOut[i].vQtdItens = (int*)realloc(pOut[i].vQtdItens, (j + 2) * sizeof(int));
                    }
                }
            }
            else if (pIn[i].qtdItens == 0)
            {
                pOut[i].itens = NULL;
                pOut[i].vQtdItens = NULL;
            }

            pOut[i].vida = pIn[i].vida;
            pOut[i].ataque = pIn[i].ataque;
            pOut[i].defesa = pIn[i].defesa;
            pOut[i].qtdItens = pIn[i].qtdItens;
        }
    }

    return &pOut[pos];
}

int main(void)
{   
    char *itensP1[] = {"Espada", "Escudo", "Pocao"};
    int qtdsP1[] = {1, 1, 5};

    char *itensP2[] = {"Arco", "Flecha"};
    int qtdsP2[] = {1, 30};
    
    Personagem vIn[3] = {
        {"Guerreiro", 100, 25, 30, 3, itensP1, qtdsP1},
        {"Arqueiro", 80, 40, 10, 2, itensP2, qtdsP2},
        {"Mago", 60, 50, 5, 0, NULL, NULL}
    };

    Personagem vOut[3];

    char *novosItens[] = {"Machado", "Bomba"};
    int novasQtds[] = {1, 3};
    int pos = 0;
    
    Personagem *substituto = substituirPersonagem(vIn, vOut, 3, pos, "Guerreiro2", 150, 60, 0, novosItens, novasQtds, 2);

    for (int i = 0; i < 3; i++)
    {
        if (&vOut[i] == substituto)
        {
            printf("\n>>>>> [PERSONAGEM SUBSTITUIDO AQUI] <<<<<\n");
        }
        else
        {
            printf("\n---------------------------------------\n");
        }

        printf("Nome: %s\n", vOut[i].nome);
        printf("Status: Vida %d | Ataque %d | Defesa %d\n", vOut[i].vida, vOut[i].ataque, vOut[i].defesa);
        printf("Quantidade de itens: %d\n", vOut[i].qtdItens);

        if (vOut[i].qtdItens > 0 && vOut[i].itens != NULL)
        {
            printf("Inventário:\n");
            for (int j = 0; j < vOut[i].qtdItens; j++)
            {
                printf(" - %d x %s\n", vOut[i].vQtdItens[j], vOut[i].itens[j]);
            }
        }
        else
        {
            printf("Inventário Vazio\n");
        }
    }
    printf("\n---------------------------------------\n");

    return 0;
}
