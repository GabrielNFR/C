int fatorial(int n) {
    if (n == 0) {
        return 1;
    }

    return n * fatorial(n - 1);
}

int potencia(int x, int y) {
    if (y == 0) {
        return 1;
    }

    return x * potencia(x, (y - 1));
}

int somaVetor(int v[], int n) {
    if (n == 0) { 
        return 0;
    }

    return v[n - 1] + somaVetor(v, n - 1);
}

void imprimeOrdem(int v[], int inicio, int fim) {
    if (inicio > fim) {
        return;
    }

    printf("%d ", v[inicio]);

    imprimeOrdem(v, inicio + 1, fim);
}

int maiorElemento(int v[], int n) {
    if (n == 1) {
        return v[0];
    }

    int maiorResto = maiorElemento(v, n - 1);

    return v[n - 1] > maiorResto ? v[n - 1] : maiorResto;
}