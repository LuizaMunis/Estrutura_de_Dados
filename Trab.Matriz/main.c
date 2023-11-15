
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

    
    A = leMatriz(arquivo);
    B = leMatriz(arquivo2);

    printf("Matriz A:\n");
    imprimeMatriz(A);

    printf("\nMatriz B:\n");
    imprimeMatriz(B);

    
    C = somaMatrizes(A, B);
    printf("\nSoma das matrizes\n");
    imprimeMatriz(C);

    
    fclose(arquivo);
    fclose(arquivo2);
    liberaMatriz(&A);
    liberaMatriz(&B);
    liberaMatriz(&C);

    return 0;
}