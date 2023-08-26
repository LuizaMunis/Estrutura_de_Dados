/*Crie um programa que declare uma matriz de inteiros 4x4 e preencha-a com valores aleatórios. Em seguida,
encontre e exiba a soma de todos os elementos da matriz.*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
    int matriz[4][4];

    srand(time(NULL));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++){

            matriz[i][j] = rand() % 100;

         }
        }


    printf("Matriz 4x4 digitada:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
