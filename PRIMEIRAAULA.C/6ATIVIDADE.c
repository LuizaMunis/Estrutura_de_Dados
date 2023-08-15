#include<stdio.h>
/* A passagem de parâmetro se dar por valor, logo, a função não modifica
o vetor fora dela.*/

void exibirArray(int array[], int tamanho){
    for (int i=0;i<tamanho;i++)

    printf("%d\t", array[i]);
    printf("\n");
}

int main(){
    int meuArray[]={2,5,6,9,0};
    int tamanho=sizeof(meuArray)/sizeof(meuArray[0]);//cuida do tamanho do vetor

    exibirArray(meuArray,tamanho);

    return 0;
}