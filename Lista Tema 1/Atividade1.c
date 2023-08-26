/*Implemente, em C, um algoritmo que declare um vetor (array) de inteiros com 5 elementos; preencha-o com
valores digitados pelo usuário e, em seguida, exiba a soma de todos os elementos do array.*/

#include <stdio.h>

int somaVetor(int vetor[]) {
    int soma = 0;
    for (int i = 0; i < 5; i++) {
        soma += vetor[i];
    }
    return soma;
}

int main() {
    int vetor[5], i = 0;
    int soma = 0; // Inicialize a variável soma com zero

    for (i = 0; i < 5; i++) {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    soma = somaVetor(vetor); // Atribua o resultado da função à variável soma

    printf("Resultado: %d\n", soma);

    return 0;
}
