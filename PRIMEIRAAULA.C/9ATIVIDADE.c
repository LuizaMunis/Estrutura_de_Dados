#include <stdio.h>

int *criarVetor(int tamanho){

    int *Vetor=malloc(tamanho*sizeof(int));// alocação dinamica de memoria
    for (int i=0;i <tamanho;i++)
        Vetor[i]=2*i+3;

    return Vetor;

}

int main (){
    int tamanho;
    printf("Digite o tamanho do vetor:");
    scanf("%d",&tamanho);

    int *meuVetor=criarVetor(tamanho);

    for(int i=0;i<tamanho;i++)
    printf("%d\t",meuVetor[i]);

    free(meuVetor);

    return 0;
}