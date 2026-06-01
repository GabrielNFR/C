int estaNoVetor(int v[], int n, int x) {
    if (n == 0) {
        return 0;
    }

    if (v[n - 1] == x) {
        return 1;
    }

    return estaNoVetor(v, n - 1, x);
}