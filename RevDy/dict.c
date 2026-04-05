#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{   
    int n;
    scanf("%d", &n);
    
    char **lista = (char**)malloc(n * sizeof(char*));
    char buffer[50];

    for (int i = 0; i < n; i++)
    {
        scanf(" %49[^\n]", buffer);
        int len = strlen(buffer) + 1;
        lista[i] = (char*)malloc(len * sizeof(char));
        strcpy(lista[i], buffer);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%s ", lista[i]);
    }

    for (int i = 0; i < n; i++)
    {
        free(lista[i]);
    }
    free(lista);

    return 0;
}