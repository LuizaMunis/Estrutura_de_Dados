#include<stdio.h>
#include <string.h>

struct Pessoa{
    char nome[20];
    int idade;
    float altura;
};

int main(){
    struct Pessoa X;
    strcpy(X.nome,"joao");
    X.idade=25;
    X.altura=1.70;

    printf("O nome da pessoa e %s, que tem %d anos e mede %.2fm de altura",X.nome,X.idade,X.altura)

}