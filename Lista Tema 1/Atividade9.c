/*Crie uma struct chamada "Funcionario" que armazene o nome, o salário e o cargo de um funcionário. Em
seguida, declare um array de 4 elementos do tipo "Funcionario" e preencha-o com dados digitados pelo usuário.
Por fim, exiba os dados dos funcionários na tela.*/

#include <stdio.h>

struct Funcionario {
    char nome[50];
    float salario;
    char cargo[50];
};

int main() {
    struct Funcionario funcionarios[4];

    printf("Digite os dados de 4 funcionários:\n");
    for (int i = 0; i < 4; i++) {
        printf("Funcionário %d:\n", i + 1);
        
        printf("Nome: ");
        scanf("%s", funcionarios[i].nome);
        fflush(stdin);
    

        printf("Salário: ");
        scanf("%f", &funcionarios[i].salario);
         fflush(stdin);

        printf("Cargo: ");
        scanf("%s", funcionarios[i].cargo);
         fflush(stdin);

        printf("\n");
    }

    printf("Dados dos funcionários:\n");
    for (int i = 0; i < 4; i++) {
        printf("Funcionário %d:\n", i + 1);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Salário: %.2f\n", funcionarios[i].salario);
        printf("Cargo: %s\n\n", funcionarios[i].cargo);
    }

}

