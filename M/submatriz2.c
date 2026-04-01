#include <stdio.h>

void montarSubmatriz(int R, int C, int I[R], int J[C], float A[4][5], float B[R][C]);

#include <stdio.h>

int main(void)
{
    float A[4][5] = {{1.5, -2.0, 3.1, 0.0, 4.2},
                     {5.0, 8.3, -1.1, 2.5, 7.0},
                     {-3.4, 0.5, 9.9, -4.0, 1.2},
                     {6.1, 2.2, -5.5, 3.3, 8.8}};
    
    int R;
    printf("Qtd linhas submatriz: ");
    scanf("%d", &R);
    
    int I[R];
    for (int k = 0; k < R; k++)
    {
        printf("Escolha a linha %d da submatriz: ", k + 1);
        scanf("%d", &I[k]);
    }

    int C;
    printf("Qtd colunas submatriz: ");
    scanf("%d", &C);
    
    int J[C];
    for (int k = 0; k < C; k++) 
    {
        printf("Escolha a coluna %d da submatriz: ", k + 1);
        scanf("%d", &J[k]);
    }

    float B[R][C];

    montarSubmatriz(R, C, I, J, A, B);

    printf("\nMatriz B Gerada:\n");
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            printf("%.1f\t", B[i][j]); 
        }
        printf("\n"); 
    }

    return 0;
}

void montarSubmatriz(int R, int C, int I[R], int J[C], float A[4][5], float B[R][C])
{
    for (int r = 0; r < R; r++)
    {
        for (int s = 0; s < C; s++)
        {
            B[r][s] = A[I[r]][J[s]];
        }
    }
}