#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *f = fopen("mensagem.txt", "r");

    if (f == NULL) {
        exit(1);
    } else {
        char c[100];
        fgets(c, 100, f);
        printf("%s", c);
    }

    fclose(f);

    return 0;
}