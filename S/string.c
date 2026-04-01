#include <stdio.h>
#include <string.h> 

int main() {
    int tabelaLeds[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int n;
    char stringNumero[105];
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%s", stringNumero); 
        
        int total = 0; 
        
        int tamanho = strlen(stringNumero);
        
        for (int j = 0; j < tamanho; j++) {

            int digitoAtual = stringNumero[j] - '0';
            total += tabelaLeds[digitoAtual];
        }
        
        printf("%d leds\n", total);
    }

    return 0;
}