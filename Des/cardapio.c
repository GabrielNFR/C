#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *nome;
    int qtdGramas;
}Ingrediente;

typedef struct
{
    char *nome;
    int tPreparo;
    int dificuldade;
    int calorias;
    int qtdIngredientes;
    Ingrediente **listaIngredientes;
}Prato;

Prato* atualizarCardapio(Prato *pIn, Prato *pOut, int tam, int pos, char *novoPrato, int tPreparo, int dificuldade, int calorias, char **ingredientesNovoP, int *qtdGramas, int qtdIngredientes)
{
    for (int i = 0; i < tam; i++)
    {
        if (i == pos)
        {
           pOut[i].nome = (char*)calloc(strlen(novoPrato) + 1, sizeof(char));
           strcpy(pOut[i].nome, novoPrato);

           pOut[i].tPreparo = tPreparo;
           pOut[i].dificuldade = dificuldade;
           pOut[i].calorias = calorias;
           pOut[i].qtdIngredientes = qtdIngredientes;

           if (qtdIngredientes > 0)
           {
              pOut[i].listaIngredientes = (Ingrediente**)calloc(1, sizeof(Ingrediente*));

              for (int j = 0; j < qtdIngredientes; j++)
              {
                 if (j > 0)
                 {
                    pOut[i].listaIngredientes = (Ingrediente**)realloc(pOut[i].listaIngredientes, (j + 1) * sizeof(Ingrediente*));
                 }

                 pOut[i].listaIngredientes[j] = (Ingrediente*)calloc(1, sizeof(Ingrediente));
                 pOut[i].listaIngredientes[j]->nome = (char*)calloc(strlen(ingredientesNovoP[j]) + 1, sizeof(char));

                 strcpy(pOut[i].listaIngredientes[j]->nome, ingredientesNovoP[j]);
                 pOut[i].listaIngredientes[j]->qtdGramas = qtdGramas[j];
              }
           }
           else
           {
            pOut[i].listaIngredientes = NULL;
           }
        }
        else
        {
            pOut[i].nome = (char*)calloc(strlen(pIn[i].nome) + 1, sizeof(char));
            strcpy(pOut[i].nome, pIn[i].nome);

           pOut[i].tPreparo = pIn[i].tPreparo;
           pOut[i].dificuldade = pIn[i].dificuldade;
           pOut[i].calorias = pIn[i].calorias;
           pOut[i].qtdIngredientes = pIn[i].qtdIngredientes;

           if (pIn[i].qtdIngredientes > 0)
           {
             pOut[i].listaIngredientes = (Ingrediente**)calloc(1, sizeof(Ingrediente*));

             for (int j = 0; j < pIn[i].qtdIngredientes; j++)
             {
                if (j > 0)
                {
                   pOut[i].listaIngredientes = (Ingrediente**)realloc(pOut[i].listaIngredientes, (j + 1) * sizeof(Ingrediente*));
                }

                pOut[i].listaIngredientes[j] = (Ingrediente*)calloc(1, sizeof(Ingrediente));
                pOut[i].listaIngredientes[j]->nome = (char*)calloc(strlen(pIn[i].listaIngredientes[j]->nome) + 1, sizeof(char));

                strcpy(pOut[i].listaIngredientes[j]->nome, pIn[i].listaIngredientes[j]->nome);
                pOut[i].listaIngredientes[j]->qtdGramas = pIn[i].listaIngredientes[j]->qtdGramas;
             }
           }
           else
           {
             pOut[i].listaIngredientes = NULL;
           }
        }
    }

    return &pOut[pos];
}

int main(void)
{   
    char *ingredientesNovos[] = {"Farinha de trigo", "Molho de tomate", "Queijo mussarela", "Fermento"};
    int qtdGramasNovos[4] = {250, 100, 200, 5};

    Ingrediente *listaP1[] = {
        &(Ingrediente){"Macarrão", 400},
        &(Ingrediente){"Molho de carne", 200}
    };

    Ingrediente *listaP2[] = {
        &(Ingrediente){"Alface", 100},
        &(Ingrediente){"Tomate", 150},
        &(Ingrediente){"Cebola", 50}
    };

    Ingrediente *listaP3[] = {
    
        &(Ingrediente){"Frango", 300},
        &(Ingrediente){"Batata", 250}
    };

    Prato vIn[3] = {
        {"Macarronada", 20, 1, 600, 2, listaP1},
        {"Salada Mista", 10, 1, 150, 3, listaP2},
        {"Frango Assado", 50, 2, 800, 2, listaP3}
    };

    Prato vOut[3];

    Prato *pMod = atualizarCardapio(vIn, vOut, 3, 2, "Pizza de Mussarela", 40, 2, 1200, ingredientesNovos, qtdGramasNovos, 4);

    printf("\nCARDAPIO ATUALIZADO\n");
    for (int i = 0; i < 3; i++)
    {
        if (&vOut[i] == pMod)
        {
            printf("\nPRATO MAIS RECENTE!!!\n");
        }
        else
        {
            printf("\n---------------------------------------\n");
        }
        
        printf("Nome: %s\n", vOut[i].nome);
        printf("Tempo de preparo: %d\n", vOut[i].tPreparo);
        printf("Dificuldade: %d\n", vOut[i].dificuldade);
        printf("Calorias: %d\n", vOut[i].calorias);
        printf("Quantidade de ingredientes: %d\n", vOut[i].qtdIngredientes);
        printf("Lista de ingredientes:\n");
        for (int j = 0; j < vOut[i].qtdIngredientes; j++)
        {
            printf("Ingrediente %d: %s | Qtd: %d\n", j + 1, vOut[i].listaIngredientes[j]->nome, vOut[i].listaIngredientes[j]->qtdGramas);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        free(vOut[i].nome);

        if (vOut[i].listaIngredientes != NULL)
        {
            for (int j = 0; j < vOut[i].qtdIngredientes; j++)
            {
                free(vOut[i].listaIngredientes[j]->nome);
                free(vOut[i].listaIngredientes[j]);
            }
            free(vOut[i].listaIngredientes);
        }
    }

    return 0;
}