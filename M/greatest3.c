#include <stdio.h>
#include <stdlib.h>
 
int maior(int a, int b, int c);

int main() {
    int a, b, c;
    
    scanf("%d %d %d", &a, &b, &c);
    
    int resultado = maior(a, b, c);
    
    printf("%d eh o maior", resultado);
    
    return 0;
}

int maior(int a, int b, int c)
{
    int maiorAB = (a + b + abs(a - b)) / 2;
    int maiorABC = (maiorAB + c + abs(maiorAB - c)) / 2;
    
    return maiorABC;
}