#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{   
    char str1[100];
    char str2[100];
    char *str3;

    scanf(" %99[^\n]", str1);
    scanf(" %99[^\n]", str2);
    
    int len = strlen(str1) + strlen(str2) + 1;

    str3 = (char*)malloc(len * sizeof(char));

    if (str3 == NULL)
    {
        return 1;
    }

    int i = 0;
    int j = 0;

    while (str1[j] != '\0')
    {
        str3[i] = str1[j];
        i++;
        j++;
    }

    j = 0;
    while (str2[j] != '\0')
    {
        str3[i] = str2[j];
        i++;
        j++;
    }

    str3[i] = '\0';

    printf("%s\n", str3);

    free(str3);

    return 0;
}