/*Crie um programa que declare uma matriz de inteiros 3x3 e preencha-a com valores digitados pelo usuário. Em
seguida, exiba a matriz na tela.*/

#include <stdio.h>

int main() {
    int matriz[3][3];
    
    printf("Digite os valores para a matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Digite o valor para a posicao [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    printf("Matriz 3x3 digitada:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
                      
