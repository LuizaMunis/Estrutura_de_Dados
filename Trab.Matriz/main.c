
#include <stdio.h>
#include "matriz.h"

int main() {
    Matriz A, B, C;
    FILE *arquivo, *arquivo2;

    arquivo = fopen("matrizA.txt", "r");
    arquivo2 = fopen("matrizB.txt", "r");

    if (arquivo == NULL || arquivo2 == NULL) {
        printf("Erro ao abrir os arquivos\n");
        return 1;
    }

    
    A = lerMatriz(arquivo);
    B = lerMatriz(arquivo2);

    printf("Matriz A:\n");
    imprimeMatriz(A);

    printf("\nMatriz B:\n");
    imprimir(B);
    C = somar(A, B);
    printf("\nSoma das matrizes\n");
    imprimir(C);
    fclose(arquivo);
    fclose(arquivo2);
    deletar(&A);
    deletar(&B);
    deletar(&C);

    return 0;
}