/*Crie um programa que declare uma matriz de inteiros 3x3 e preencha-a com valores digitados pelo usuário. Em
seguida, encontre e exiba o maior valor presente na matriz.*/

#include <stdio.h>

int main()
{
    int matriz[3][3];
    int maior = 0;

    printf("Digite os valores para a matriz 3x3:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Digite o valor para a posicao [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            if (matriz[i][j] > maior)
            {
                maior = matriz[i][j];
            }
        }
    }

    printf("\nMatriz digitada:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nO maior valor na matriz e: %d\n", maior);
}
