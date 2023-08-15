#include <stdio.h>

int main(){

int numeros[5]= {1,2,3,4,5};
char nome[10]="Exemplo";

printf("Terceiro elemento do vetor:%d\n", numeros[2]);
printf("Primeiro elemento do vetor: %c\n", nome[0]);
printf("Teste 01: %d\n", nome[0]);// retorna numero da tabela "nao sei escrever"
printf("Teste 01: %c\n", nome[0]+1);

    return 0;
}