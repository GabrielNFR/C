#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    int n;
    scanf("%d", &n);

    float **boletim = (float**)calloc(n, sizeof(float*));

    int *qtd_notas = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &qtd_notas[i]);

        if (qtd_notas[i] > 0)
        {
            boletim[i] = (float*)calloc(qtd_notas[i], sizeof(float));
            for (int j = 0; j < qtd_notas[i]; j++)
            {
                scanf("%f", &boletim[i][j]);
            }
        }
        else
        {
            boletim[i] = NULL;
        }
    }

    float somaGeral = 0;
    float totalNotas = 0;

    for (int i = 0; i < n; i++)
    {
        float somaDisciplina = 0;
        if (qtd_notas[i] > 0)
        {
            for (int j = 0; j < qtd_notas[i]; j++)
            {
                somaDisciplina += boletim[i][j];
                somaGeral += boletim[i][j];
                totalNotas++;
            }

            float mediaDisciplina = somaDisciplina / qtd_notas[i];
            printf("Media da disciplina %d: %.2f\n", i + 1, mediaDisciplina);
        }
        else
        {
            printf("Media da disciplina %d: N/A (Sem notas)\n", i + 1);
        }
    }

    if (totalNotas > 0)
    {
        printf("\nMedia Geral do aluno: %.2f\n", somaGeral / totalNotas);
    }
    else
    {
        printf("\nO aluno nao obteve nenhuma nota.\n");
    }

    for (int i = 0; i < n; i++)
    {
        free(boletim[i]);
    }
    free(boletim);
    free(qtd_notas);
    
    return 0;
}