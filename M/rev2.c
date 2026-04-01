#include <stdio.h>

int Identidade(int N, int M[3][3]);

int main(void)
{   
    int M[3][3] = {{1, 0, 0},
                   {0, 1, 0},       
                   {0, 0, 2}};
    
    int identidade = Identidade(3, M);
    
    if (identidade == 1)
    {
        printf("%d", identidade);
    }
    else
    {
        printf("%d", identidade);
    }

    return 0;
}

int Identidade(int N, int M[3][3])
{
    int identidade = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j && M[i][j] != 1)
            {
                identidade = 0;
                break;
            }
            else if (i != j && M[i][j] != 0)
            {
                identidade = 0;
                break;
            }
            
        }
    }
    return identidade;
}