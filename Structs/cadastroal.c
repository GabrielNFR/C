#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno
{
    float nota1;
    float nota2;
    float nota3;
    char nome[50];
}Aluno;

float calcularMediaAluno(Aluno a)
{
    float media = (a.nota1 + a.nota2 + a.nota3) / 3;
    return media;
}

int buscarMelhorAluno(int n, Aluno v[n])
{
    float melhor = calcularMediaAluno(v[0]);
    int melhorIndice = 0;
    
    for (int i = 1; i < n; i++)
    {
       float mediaAtual = calcularMediaAluno(v[i]);
       if (mediaAtual > melhor)
       {
            melhor = mediaAtual;
            melhorIndice = i;     
       }
    }

    return melhorIndice;
}

int main(void)
{   
    int n;
    scanf("%d", &n);

    Aluno v[n];

    for (int i = 0; i < n; i++)
    {
        scanf(" %49[^\n]", v[i].nome);
        scanf("%f", &v[i].nota1);
        scanf("%f", &v[i].nota2);
        scanf("%f", &v[i].nota3);
    }

    int melhor = buscarMelhorAluno(n, v);
    float media = calcularMediaAluno(v[melhor]);

    printf("Nome: %s\nMédia: %.2f\n", v[melhor].nome, media);

    return 0;
}