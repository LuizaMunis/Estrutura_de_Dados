/*Crie uma struct chamada "Livro" que armazene o título, o autor e o ano de lançamento de um livro. Em seguida,
declare um array de 5 elementos do tipo "Livro" e preencha-o com dados digitados pelo usuário. Por fim, exiba os
dados dos livros na tela.*/

#include <stdio.h>

struct Livro
{
    char titulo[50];
    char autor[50];
    int ano;
};

int main()
{
    struct Livro livro[5];

    for (int i = 0; i < 5; i++)
    {

        printf("Digite o nome do %d livro:", i + 1);
        fgets(livro[i].titulo, 50, stdin);
        fflush(stdin);

        printf("Digite o nome do autor %d livro:", i + 1);
        fgets(livro[i].autor, 50, stdin);
        fflush(stdin);

        printf("Digite o ano %d livro foi lancado:", i + 1);
        scanf("%d", &livro[i].ano);
        fflush(stdin);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("Livro:%s\tAutor:%s\tLancamento:%d\n", livro[i].titulo, livro[i].autor, livro[i].ano);
    }
}
