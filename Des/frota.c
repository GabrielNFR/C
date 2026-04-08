#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int **mapaSetores;
    char **tripulantes;
    char *nome;
    int nivelEnergia;
    int quantidadeTripulantes;
    int linhasMapa;
    int colunasMapa;
}Nave;

Nave* atualizarFrota(Nave *nIn, Nave *nOut, int tamFrota, int posAlvo, int energiaAdicional, int qtdNovosTripulantes, char **novosTripulantes, int novasLinhas, int novasColunas, int **mapaSetores)
{
    for (int i = 0; i < tamFrota; i++)
    {
        if (nIn[i].quantidadeTripulantes == 0)
        {
            nOut[i].tripulantes = NULL;
        }
        else
        {
            nOut[i].tripulantes = (char**)malloc(nIn[i].quantidadeTripulantes * sizeof(char*));
        
            for (int j = 0; j < nIn[i].quantidadeTripulantes; j++)
            {
                nOut[i].tripulantes[j] = (char*)calloc(strlen(nIn[i].tripulantes[j]) + 1, sizeof(char));
                strcpy(nOut[i].tripulantes[j], nIn[i].tripulantes[j]);
            }
        }

        nOut[i].quantidadeTripulantes = nIn[i].quantidadeTripulantes;
        nOut[i].nome = (char*)calloc(strlen(nIn[i].nome) + 1, sizeof(char));
        strcpy(nOut[i].nome, nIn[i].nome);

        if (i == posAlvo)
        {
            nOut[i].nivelEnergia = nIn[i].nivelEnergia + energiaAdicional;
            if (qtdNovosTripulantes > 0)
            {
                int temp = nIn[i].quantidadeTripulantes;
                for (int k = 0; k < qtdNovosTripulantes; k++)
                {
                    nOut[i].tripulantes = (char**)realloc(nOut[i].tripulantes, (temp + k + 1) * sizeof(char*));
                    nOut[i].tripulantes[temp + k] = (char*)calloc(strlen(novosTripulantes[k]) + 1, sizeof(char));
                    strcpy(nOut[i].tripulantes[temp + k], novosTripulantes[k]);
                }

                nOut[i].quantidadeTripulantes = temp + qtdNovosTripulantes;
            }

            if (novasLinhas == 0 || novasColunas == 0)
            {
                nOut[i].mapaSetores = NULL;
            }
            else
            {
                nOut[i].mapaSetores = (int**)calloc(novasLinhas, sizeof(int*));
                for (int j = 0; j < novasLinhas; j++)
                {
                    nOut[i].mapaSetores[j] = (int*)calloc(novasColunas, sizeof(int));
                }

                for (int j = 0; j < novasLinhas; j++)
                {
                    for (int k = 0; k < novasColunas; k++)
                    {
                        nOut[i].mapaSetores[j][k] = mapaSetores[j][k];
                    }
                }

                nOut[i].linhasMapa = novasLinhas;
                nOut[i].colunasMapa = novasColunas;
            }        
        }
        else
        {
            nOut[i].nivelEnergia = nIn[i].nivelEnergia;
            
            if (nIn[i].linhasMapa == 0 || nIn[i].colunasMapa == 0)
            {
                nOut[i].mapaSetores = NULL;
            }
            else
            {
                nOut[i].mapaSetores = (int**)calloc(nIn[i].linhasMapa, sizeof(int*));
                for (int j = 0; j < nIn[i].linhasMapa; j++)
                {
                    nOut[i].mapaSetores[j] = (int*)calloc(nIn[i].colunasMapa, sizeof(int));
                }

                for (int j = 0; j < nIn[i].linhasMapa; j++)
                {
                    for (int k = 0; k < nIn[i].colunasMapa; k++)
                    {
                        nOut[i].mapaSetores[j][k] = nIn[i].mapaSetores[j][k];
                    }
                }

                nOut[i].linhasMapa = nIn[i].linhasMapa;
                nOut[i].colunasMapa = nIn[i].colunasMapa;
            }
        }
    }

    return &nOut[posAlvo];
}
int main(void)
{   
    int m1[5][5] = {{1, 2, 3, 4, 5}, 
                    {6, 7, 8, 9, 10}, 
                    {11, 12, 13, 14, 15}, 
                    {16, 17, 18, 19, 20}, 
                    {21, 22, 23, 24, 25}};

    int *pM1[5];
    for (int i = 0; i < 5; i++)
    {
        pM1[i] = m1[i];
    }

    int *pM2[5];
    for (int i = 0; i < 5; i++)
    {
        pM2[i] = m1[i];
    }

    int *pM3[5];
    for (int i = 0; i < 5; i++)
    {
        pM3[i] = m1[i];
    }

    char *tripulantes[] = {"trip1", "trip2", "trip3", "trip4", "trip5"};
    char *tripulantes2[] = {"trip100", "trip101", "trip103", "trip104", "trip105"};
    char *tripulantes3[] = {"trip130", "trip131", "trip133", "trip134", "trip135"};
    
    Nave vIn[2] = {
        {pM1, tripulantes, "Aurora", 15000, 5, 5, 5},
        {pM2, tripulantes2, "Enterprise", 30000, 5, 5, 5}
    };

    Nave vOut[2];

    Nave *nMod = atualizarFrota(vIn, vOut, 2, 1, 10000, 5, tripulantes3, 5, 5, pM3);

    printf("\n==== NAVE ATUALIZADA ====\n");
    printf("Nome: %s\n", nMod->nome);
    printf("Energia: %d\n", nMod->nivelEnergia);
    printf("Qtd Tripulantes: %d\n", nMod->quantidadeTripulantes);
    
    printf("\n-- Lista de Tripulantes --\n");
    if (nMod->tripulantes != NULL) {
        for (int i = 0; i < nMod->quantidadeTripulantes; i++) {
            printf(" [%d] %s\n", i + 1, nMod->tripulantes[i]);
        }
    } else {
        printf(" Nenhum tripulante a bordo.\n");
    }

    printf("\n-- Mapa de Setores (%dx%d) --\n", nMod->linhasMapa, nMod->colunasMapa);
    if (nMod->mapaSetores != NULL) {
        for (int i = 0; i < nMod->linhasMapa; i++) {
            printf(" ");
            for (int j = 0; j < nMod->colunasMapa; j++) {
                printf("%3d ", nMod->mapaSetores[i][j]);
            }
            printf("\n");
        }
    } else {
        printf(" Sem mapa disponivel.\n");
    }
    printf("=========================\n\n");

    for (int i = 0; i < 2; i++)
    {
        free(vOut[i].nome);

        if (vOut[i].tripulantes != NULL)
        {
            for (int j = 0; j < vOut[i].quantidadeTripulantes; j++)
            {
                free(vOut[i].tripulantes[j]);
            }
            free(vOut[i].tripulantes);
        }

        if (vOut[i].mapaSetores != NULL) 
        {
            for (int j = 0; j < vOut[i].linhasMapa; j++) 
            {
                free(vOut[i].mapaSetores[j]);
            }
            free(vOut[i].mapaSetores);
        }
    }

    return 0;
}