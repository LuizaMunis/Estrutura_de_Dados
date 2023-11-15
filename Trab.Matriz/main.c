
#include <stdio.h>
#include "matriz.h"

int main() {
    Matriz A, B, C;
    FILE *arquivo, *arquivo2;

    arquivo = fopen("Trab.Matriz\\matrizA.txt", "r");
    arquivo2 = fopen("Trab.Matriz\\matrizB.txt", "r");

    if (arquivo == NULL || arquivo2 == NULL) {
        printf("Erro ao abrir os arquivos\n");
        return 1;
    }

    A = lerMatriz(arquivo);
    printf("Matriz A:\n");
    imprimir(A);

    B = lerMatriz(arquivo2);
    C = somar(A, B);
    printf("\nSoma\n");
    imprimir(C);

    C= multiplicar(A,B);
    printf("\nMultiplicação\n");
    imprimir(C);

    deletar(&A);
    deletar(&B);
    deletar(&C);

    fclose(arquivo);
    fclose(arquivo2);

    return 0;
}