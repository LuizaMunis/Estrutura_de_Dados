
/*Crie um programa que declare um N de inteiros com 6 elementos e preencha-o com valores digitados pelo
usuário. Em seguida, calcule e exiba a média dos valores presentes no N.*/


#include <stdio.h>

int main() {
    int N[6];
    float soma = 0;

    printf("Digite 6 valores inteiros:\n");
    for (int i = 0; i < 6; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &N[i]);
        soma += N[i]; 
    }

    float media = soma / 6;

    printf("Valores digitados: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", N[i]);
    }
    printf("\n");

    printf("A média dos valores é: %.2f\n", media);

}
