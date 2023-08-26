/*Crie uma struct chamada "Aluno" que armazene o nome e a nota de um aluno. Em seguida, declare um array de
3 elementos do tipo "Aluno" e preencha-o com dados digitados pelo usuário. Por fim, exiba os dados dos alunos
na tela.*/

#include <stdio.h>
#include <string.h>

struct Aluno
{
    char nome[20];
    float nota;
};

int main(){

    struct Aluno aluno[3];
    int i = 0;

    for (i = 0; i < 3; i++)
    {

        printf("Digite o nome do %d aluno:", i + 1);
        fgets(aluno[i].nome, 20, stdin);
        fflush(stdin);

        printf("Digite a nota  do %d aluno:", i + 1);
        scanf("%f", &aluno[i].nota);
         fflush(stdin);
    }

    for (i = 0; i < 3; i++)
    {

        printf("Aluno:%s\t Nota:%2.f", aluno[i].nome, aluno[i].nota);
    }
}


