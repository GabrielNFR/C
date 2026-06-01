#include <stdio.h>
#include <stdlib.h>

void copiarArquivo(char* origem, char* destino) {
    FILE *fo = fopen(origem, "r");
    FILE *fd = fopen(destino, "w");

    if (fo == NULL || fd == NULL) {
        exit(1);
    }

    int c;
    while ((c = fgetc(fo)) != EOF) {
        fputc(c, fd);
    }
    
    fclose(fo);
    fclose(fd);
}

int main(void) {
    copiarArquivo("mensagem.txt", "mensagemCopiada.txt");
    return 0;
}