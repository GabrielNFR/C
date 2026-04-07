#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct
{
    Data nascimento;
    char nome[50];
}Pessoa;

void ordenarPorIdade(int n, Pessoa v[n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i].nascimento.ano > v[j].nascimento.ano)
            {
                Pessoa temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }

            if (v[i].nascimento.ano == v[j].nascimento.ano)
            {
                if (v[i].nascimento.mes > v[j].nascimento.mes)
                {
                    Pessoa temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
            }

            if (v[i].nascimento.ano == v[j].nascimento.ano && v[i].nascimento.mes == v[j].nascimento.mes)
            {
                if (v[i].nascimento.dia > v[j].nascimento.dia)
                {
                    Pessoa temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
            }
        }
    }
}

int main(void)
{   
    int n;
    scanf("%d", &n);

    Pessoa v[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &v[i].nascimento.ano, &v[i].nascimento.mes, &v[i].nascimento.dia);
        scanf("%s", v[i].nome);
    }

    ordenarPorIdade(n, v);

    for (int i = 0; i < n; i++)
    {
        printf("%s | %d/%d/%d\n", v[i].nome, v[i].nascimento.dia, v[i].nascimento.mes, v[i].nascimento.ano);
    }

    return 0;
}