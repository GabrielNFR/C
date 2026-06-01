#include <stdio.h>

int contaPares(int v[], int n) {
    if (n == 0) {
        return 0;
    }
    return (v[n - 1] % 2 == 0 ? 1 : 0) + contaPares(v, n - 1);
}