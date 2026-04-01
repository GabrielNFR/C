#include <stdio.h>

int main(){
    
    int ano, mes, idx;
    char r [4];

    printf("Calcular Idx ou T?\n");
    scanf("%s", &r);

    if (r == "idx")
    {
        scanf("%d, %d", &ano, &mes);
        idx = ano * 12 + mes;
        printf("%d\n", idx);
    }
    else
    {
        scanf("%d", &idx);
        ano = idx / 12;
        mes = idx % 12;
        printf("%d, %d\n", ano, mes);
    }
    
    return 0;
}

