#include <stdio.h>
#include <limits.h>

void menorDiferenca(int R, int C, int K, int M[R][C]);

int main(void)
{
    int R, C, K;

    printf("Linhas: ");
    scanf("%d", &R);
    printf("Colunas: ");
    scanf("%d", &C);
    printf("Lote: ");
    scanf("%d", &K);
    
    int M[R][C];

    for (int i = 0; i < R ; i++)
    {
        for (int j = 0; j < C; j++)
        {
            scanf("%d", &M[i][j]);
        }
    }

    menorDiferenca(R, C, K, M);

    return 0;
}

void menorDiferenca(int R, int C, int K, int M[R][C])
{
    int menorDiferenca = INT_MAX;
    int melhorLinha = 0;
    int melhorColuna = 0;

    for (int i = 0; i <= R - K; i++)
    {
        for (int j = 0; j <= C - K; j++)
        {
            int maior_valor = M[i][j];
            int menor_valor = M[i][j];

            for (int a = i; a <= i + K - 1; a++)
            {
                for (int b = j; b <= j + K - 1; b++)
                {
                    if (M[a][b] > maior_valor)
                    {
                        maior_valor = M[a][b]; 
                    }
                    
                    if (M[a][b] < menor_valor)
                    {
                        menor_valor = M[a][b]; 
                    }
                }
            }
            int diferenca_atual = maior_valor - menor_valor;
            if (diferenca_atual < menorDiferenca)
            {
                menorDiferenca = diferenca_atual;
                melhorLinha = i;
                melhorColuna = j;
            }           
        }
    }
    printf("Menor diferença de altitude: %d\n", menorDiferenca);
    printf("Lote escolhido:\n");

    for (int r = 0; r < K; r++)
    {
        for (int s = 0; s < K; s++)
        {
            printf("%d ", M[melhorLinha + r][melhorColuna + s]);
        }
        printf("\n");
    } 
}