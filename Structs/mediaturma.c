#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno
{
    float notas[4];
    char nome[50];
}Aluno;

float mediaTurma(int n, Aluno v[n])
{
    float mediaG = 0;
    for (int i = 0; i < n; i++)
    {
        float mediaA = 0;

        for (int j = 0; j < 4; j++)
        {
            mediaA += v[i].notas[j];
        }
        mediaA = mediaA / 4;
        mediaG += mediaA;
    }

    mediaG = mediaG / n;

    return mediaG;
}

int main(void)
{   
    int n;
    scanf("%d", &n);

    Aluno v[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%f", &v[i].notas[j]);
        }
        scanf("%s", v[i].nome);
    }

    float mediaG = mediaTurma(n, v);

    printf("\n%.2f\n", mediaG);

    return 0;
}