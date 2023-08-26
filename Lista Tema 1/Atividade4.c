/*Crie um programa que declare um array de inteiros com 10 elementos e preencha-o com valores aleatórios. Em
seguida, encontre e exiba o maior valor presente no array.*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int aleatorio[10];

    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        aleatorio[i] = rand() % 100;
    }

    int maior = aleatorio[0];
    for (int i = 1; i < 10; i++)
    {
        if (aleatorio[i] > maior)
        {
            maior = aleatorio[i];
        }
    }

    printf("numeros gerados: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", aleatorio[i]);
    }
    printf("\n");

    printf("O maior valor no aleatorio e: %d\n", maior);
}
