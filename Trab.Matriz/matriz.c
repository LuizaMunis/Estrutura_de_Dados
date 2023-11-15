#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matriz.h"

Celula *criaCelula(int linha, int coluna, float valor)
{

    Celula *newcel = (Celula *)malloc(sizeof(Celula));

    newcel->direita = newcel;
    newcel->abaixo = newcel;
    newcel->linha = linha;
    newcel->coluna = coluna;
    newcel->valor = valor;

    return newcel;
}

void inserir(Matriz *matriz, int i, int j, float v) {
    Celula *celula = criaCelula(i, j, v);
    Celula *atual = matriz->cabeca;

    while (atual->abaixo != matriz->cabeca && atual->abaixo->linha < celula->linha) {
        atual = atual->abaixo;
    }
    
    while (atual->direita != matriz->cabeca && atual->direita->coluna < celula->coluna) {
        atual = atual->direita;
    }

    celula->abaixo = atual->abaixo;
    atual->abaixo = celula;
    celula->direita = atual->direita;
    atual->direita = celula;
}

Matriz lerMatriz(FILE *arquivo)
{
    Matriz matriz;
    int m, n;

    // recebe o parametro
    fscanf(arquivo, "%d, %d", &m, &n);

    matriz.nlin = m;
    matriz.ncol = n;
    matriz.cabeca = criaCelula(-1, -1, 0.0);

    int i, j;
    float valor;
    while (fscanf(arquivo, "%d, %d, %f", &i, &j, &valor) == 3)
    {
        inserir(&matriz, criaCelula(i, j, valor));
    }

    return matriz;
}

void imprimir(Matriz A)
{
    for (int i = 1; i <= A.nlin; i++)
    {
        for (int j = 1; j <= A.ncol; j++)
        {
            Celula *atual = A.cabeca->direita;
            int Z = 0; // quando encontra

            while (atual != A.cabeca)
            {
                if (atual->linha == i && atual->coluna == j)
                {
                    imprimeCelula(atual);
                    Z = 1;
                    break;
                }
                atual = atual->direita;
            }

            if (!Z)
            {
                printf("(0, 0): 0.00\t");
            }
            else
            {
                Z = 0;
            }
        }
        printf("\n");
    }
}

Matriz somar(Matriz A, Matriz B)
{
    if (A.nlin != B.nlin || A.ncol != B.ncol)
    {
        printf("As matrizes devem ter mesmo valor\n");
        return 1;
    }

    Matriz C;
    C.nlin = A.nlin;
    C.ncol = A.ncol;
    C.cabeca = criaCelula(-1, -1, 0.0);

    for (int i = 1; i <= A.nlin; i++)
    {
        for (int j = 1; j <= A.ncol; j++)
        {
            float soma = 0.0;

            Celula *celulaA = A.cabeca->direita;
            Celula *celulaB = B.cabeca->direita;

            while (celulaA != A.cabeca || celulaB != B.cabeca)
            {
                if (celulaA->linha == i && celulaA->coluna == j)
                {
                    soma += celulaA->valor;
                    celulaA = celulaA->direita;
                }
                else if (celulaB->linha == i && celulaB->coluna == j)
                {
                    soma += celulaB->valor;
                    celulaB = celulaB->direita;
                }
                else
                {
                    if (celulaA->linha == i)
                    {
                        celulaA = celulaA->direita;
                    }
                    if (celulaB->linha == i)
                    {
                        celulaB = celulaB->direita;
                    }
                }
            }

            if (soma != 0.0)
            {
                inserir(&C, criaCelula(i, j, soma));
            }
        }
    }

    return C;
}

Matriz multiplicar(Matriz A, Matriz B)
{
    if (A.ncol != B.nlin)
    {
        printf("O numero de colunas estao incompativeis\n");
        return 1;
    }

    Matriz C;
    C.nlin = A.nlin;
    C.ncol = B.ncol;
    C.cabeca = criaCelula(-1, -1, 0.0);

    for (int i = 1; i <= A.nlin; i++)
    {
        for (int j = 1; j <= B.ncol; j++)
        {
            float produto = 0.0;

            for (int k = 1; k <= A.ncol; k++)
            {
                Celula *celulaA = A.cabeca->direita;
                Celula *celulaB = B.cabeca->direita;

                while (celulaA != A.cabeca && celulaA->coluna <= k)
                {
                    if (celulaA->linha == i)
                    {
                        while (celulaB != B.cabeca && celulaB->linha <= k)
                        {
                            if (celulaB->coluna == j)
                            {
                                produto += celulaA->valor * celulaB->valor;
                            }
                            celulaB = celulaB->abaixo;
                        }
                    }
                    celulaA = celulaA->direita;
                }
            }

            if (produto != 0.0)
            {
                inserir(&C, criaCelula(i, j, produto));
            }
        }
    }

    return C;
}


void deletar(Matriz *matriz)
{

    Celula *atual = matriz->cabeca->abaixo;

    while (atual != matriz->cabeca)
    {
        Celula *proximaLinha = atual->abaixo;
        Celula *celulaAtual = atual->direita;

        while (celulaAtual != atual)
        {
            Celula *proximaCelula = celulaAtual->direita;
            free(celulaAtual);
            celulaAtual = proximaCelula;
        }

        free(atual);
        atual = proximaLinha;
    }

    free(matriz->cabeca);
    matriz->cabeca = NULL;
}
