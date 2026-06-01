#include <stdio.h>

void imprimeInverso(int v[], int inicio, int fim) {
    if (fim < inicio) {
        return;
    }

    printf("%d", v[fim]);

    imprimeInverso(v, inicio, fim - 1);
}