#include <stdio.h>
 
int main() {
 
    int N;
    
    while (scanf("%d", &N) != EOF)
    {    
        int M[N][N];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i + j == N - 1)
                {
                    M[i][j] = 2;
                }
                else if (i == j)
                {
                    M[i][j] = 1;
                }
                else
                {
                    M[i][j] = 3;
                }
                printf("%d", M[i][j]);
            }
            printf("\n");
        }
    }

 
    return 0;
}