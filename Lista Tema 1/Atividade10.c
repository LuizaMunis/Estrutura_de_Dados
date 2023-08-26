/*Crie um programa que declare um array de inteiros com 8 elementos e preencha-o com valores aleatórios. Em
seguida, ordene os valores em ordem crescente e exiba o array ordenado.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    int array[8];

    srand(time(NULL));

   
    for (int i = 0; i < 8; i++) {
        array[i] = rand() % 100; 
    }

    printf("Array antes da ordenação: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    bubbleSort(array, 8);

    printf("Array ordenado: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

}

