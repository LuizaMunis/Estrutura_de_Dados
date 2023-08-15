#include<stdio.h>

struct Pessoa{
char nome[20];
int idade;
};

void modificarPessoa(struct Pessoa *p){ //referencia
    p ->idade+=1;
}

void testarPessoa(struct Pessoa X){//valor
    X.idade= X.idade*2;
}

int main(){
    struct Pessoa X = {"joao", 25};

    modificarPessoa(&X);// o & só quando variavel por referencia
    printf("Nome:%s\n",X.nome);
    printf("Idade:%d\n",X.idade);

    testarPessoa(X); //passagem por valor
    printf("Nome:%s\n",X.nome);
    printf("Idade:%d\n",X.idade);

    return 0;
}