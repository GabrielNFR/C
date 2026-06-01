#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *f = fopen("mensagem.txt", "w");

    if (f == NULL) {
        exit(1);
    } else {
        fprintf(f, "Hello World");
    }

    fclose(f);

    return 0;
}