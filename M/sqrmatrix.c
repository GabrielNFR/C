#include <stdio.h>
 
int main() {
 
    int order;
    
    while (1)
    {
        scanf("%d", &order);
        
        if (order == 0)
        {
            break;
        }
    
        for (int i = 0; i < order; i++)
        {
            for (int j = 0; j < order; j++)
            {
                int dSuperior = i;
                int dEsquerda = j;
                int dInferior = order - 1 - i;
                int dDireita = order - 1 - j;
                
                int menor = dSuperior;
                
                if (dEsquerda < menor) menor = dEsquerda;
                if (dInferior < menor) menor = dInferior;
                if (dDireita < menor) menor = dDireita;
                
                int valor = menor + 1;
                
                if (j == 0)
                {
                    printf("%3d", valor);
                }
                else
                {
                    printf(" %3d", valor);
                }
            }
            printf("\n");
        }
        printf("\n");
    }      
 
    return 0;
}