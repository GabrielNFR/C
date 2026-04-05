#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno
{
    float *notas;
    int qtdNotas;
    char nome[50];
}Aluno;


int main(void)
{   
    int n;
    scanf("%d", &n);

    Aluno alunos[n];

    for (int i = 0; i < n; i++)
    {
        scanf(" %49[^\n]", alunos[i].nome);
        scanf("%d", &alunos[i].qtdNotas);

        if (alunos[i].qtdNotas > 0)
        {
            alunos[i].notas = (float*)malloc(alunos[i].qtdNotas * sizeof(float));

            for (int j = 0; j < alunos[i].qtdNotas; j++)
            {
                scanf("%f", &alunos[i].notas[j]);
            }
        }
        else
        {
            alunos[i].notas = (float*)malloc(1 * sizeof(float));
            
            alunos[i].qtdNotas = 1;
            alunos[i].notas[0] = 0;
        }
    }

    float mediaG = 0;
    float media = 0;

    for (int i = 0; i < n; i++)
    {
        media = 0;
        
        for (int j = 0; j < alunos[i].qtdNotas; j++)
        {
            media += alunos[i].notas[j];
        }
        if (alunos[i].qtdNotas > 0)
        {
            media = media / alunos[i].qtdNotas;
        }

        printf("Média de %s: %.2f\n", alunos[i].nome, media);

        mediaG += media;
    }

    if (n > 0)
    {
        mediaG = mediaG / n;

        printf("Média geral: %.2f\n", mediaG);
    }

    for (int i = 0; i < n; i++)
    {
        free(alunos[i].notas);
    }

    return 0;
}