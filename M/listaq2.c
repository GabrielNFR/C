#include <stdio.h>

int crescente(int n, int m[3][3]);

int main(void)
{
    int m[3][3] = {{1, 3, 5},
                   {2, 4, 8},
                   {0, 7, 9}};
    
    int resultado = crescente(3, m);

    printf("%d\n", resultado);
    
    return 0;
}

int crescente(int n, int m[3][3])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (m[i][j] >= m[i][j + 1])
            {
                return 0;
            }
        }
    }
    return 1;
}