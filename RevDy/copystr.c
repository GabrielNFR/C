#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* clonarString(char *str)
{
    int len = strlen(str) + 1;
    char *s;

    s = (char*)malloc(len * sizeof(char));

    strcpy(s, str);

    return s;
}

int main(void)
{   
    char str[100];
    scanf(" %99[^\n]", str);

    char *s = clonarString(str);

    if (s != NULL) 
    {
        printf("Original: %s\nClonada: %s\n", str, s);
        
        free(s);
    }

    return 0;
}