#include <stdio.h>
#include <stdlib.h>

void tabuadaArquivo(int n) {
    FILE *f = fopen("tabuada.txt", "w");

    if (f == NULL) {
        exit(1);
    }

    for (int i = 0; i <= 10; i++) {
        fprintf(f, "%d x %d: %d\n", n, i, n * i);
    }

    fclose(f);
}

int main(void) {
    int n = 10;
    tabuadaArquivo(n);
    return 0;
}