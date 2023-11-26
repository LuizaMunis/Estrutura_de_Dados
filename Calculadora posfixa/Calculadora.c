#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct No
{
    double dado;
    struct No *proximo;
} No;

typedef struct
{
    No *topo;
} Pilha;

void inicializar(Pilha *pilha)
{
    pilha->topo = NULL;
}

void empilhar(Pilha *pilha, double valor)
{
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL)
    {
        printf("Erro: Falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }
    novoNo->dado = valor;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
}

double desempilhar(Pilha *pilha)
{
    if (pilha->topo != NULL)
    {
        No *temp = pilha->topo;
        double valor = temp->dado;
        pilha->topo = temp->proximo;
        free(temp);
        return valor;
    }
    else
    {
        printf("Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }
}

double avaliarExpressaoPosfixada(const char *expressao)
{
    Pilha pilha;
    inicializar(&pilha);
    char *endptr; // puteiro para carater, foi necessario pois nao estava lendo numeros decimais
    for (int i = 0; expressao[i] != '\0'; ++i)
    {
        if (isdigit(expressao[i]) || (expressao[i] == '-' && isdigit(expressao[i + 1]))) // verifica se o digito la é decimal
        {
            empilhar(&pilha, strtod(&expressao[i], &endptr)); // pra converte a string pra double
            i += endptr - &expressao[i] - 1;
        }
        else if (expressao[i] == ' ' || expressao[i] == '\t')
        {
            // Ignora espaços em branco
            continue;
        }
        else if (strncmp(&expressao[i], "sqrt", 4) == 0)
        {
            double operando = desempilhar(&pilha);
            empilhar(&pilha, sqrt(operando));
            i += 3;
        }
        else if (strncmp(&expressao[i], "log", 3) == 0)
        {
            double operando = desempilhar(&pilha);
            empilhar(&pilha, log10(operando));
            i += 2;
        }
        else if (strncmp(&expressao[i], "sen", 3) == 0)
        {
            double operando = desempilhar(&pilha);
            empilhar(&pilha, sin(operando));
            i += 2;
        }
        else if (strncmp(&expressao[i], "cos", 3) == 0)
        {
            double operando = desempilhar(&pilha);
            empilhar(&pilha, cos(operando));
            i += 2;
        }
        else if (strncmp(&expressao[i], "tan", 3) == 0)
        {
            double operando = desempilhar(&pilha);
            empilhar(&pilha, tan(operando));
            i += 2;
        }
        else if (expressao[i] == '+' || expressao[i] == '-' || expressao[i] == '*' || expressao[i] == '/' || expressao[i] == '^')
        {
            double operando2 = desempilhar(&pilha);
            double operando1 = desempilhar(&pilha);

            switch (expressao[i])
            {
            case '+':
                empilhar(&pilha, operando1 + operando2);
                break;
            case '-':
                empilhar(&pilha, operando1 - operando2);
                break;
            case '*':
                empilhar(&pilha, operando1 * operando2);
                break;
            case '/':
                empilhar(&pilha, operando1 / operando2);
                break;
            case '^':
                empilhar(&pilha, pow(operando1, operando2));
                break;
            }
        }
        else
        {
            printf("Erro: Expressão inválida\n");
            exit(EXIT_FAILURE);
        }
    }
    return desempilhar(&pilha);
}

int main()
{
    // Exemplo de expressão em notação pós-fixada: “2 4 + 5 *“
    const char *expressao = "3 4 + 5 tan *";
    double resultado = avaliarExpressaoPosfixada(expressao);
    printf("Resultado: %lf\n", resultado);
    return 0;
}
