#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    int linhas;
    scanf("%d", &linhas);

    int **m = (int**)malloc(linhas * sizeof(int*));

    for (int i = 0; i < linhas; i++)
    {
        m[i] = (int*)malloc((i + 1) * sizeof(int));
        
        m[i][0] = 1; 
        m[i][i] = 1; 
        
        for (int j = 1; j < i; j++)
        {
            m[i][j] = m[i-1][j-1] + m[i-1][j]; 
        }
    }

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < linhas; i++)
    {
        free(m[i]); 
    }
    free(m); 

    return 0;
}