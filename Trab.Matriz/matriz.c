
#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"

Celula *criar(int linha, int coluna, float valor){
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    novo->direita = novo;
    novo->abaixo = novo;
    novo->linha = linha;
    novo->coluna = coluna;
    novo->valor = valor;

    return novo;
}

void inserir(Matriz *matriz, int i, int j, float v) {
    Celula *novaCelula = criar(i, j, v);

    Celula *atual = matriz->cabeca;
    while (atual->abaixo != matriz->cabeca && atual->abaixo->linha < novaCelula->linha) {
        atual = atual->abaixo;}

    while (atual->direita != matriz->cabeca && atual->direita->coluna < novaCelula->coluna) {
        atual = atual->direita;}

    novaCelula->abaixo = atual->abaixo;
    atual->abaixo = novaCelula;

    novaCelula->direita = atual->direita;
    atual->direita = novaCelula;
}


void imprimir(Matriz A) {
    for (int i = 1; i <= A.nlin; i++) {
        for (int j = 1; j <= A.ncol; j++) {
            Celula *atual = A.cabeca->direita;
            int z = 0;//pra ver se encontrou

            while (atual != A.cabeca) {
                if (atual->linha == i && atual->coluna == j) {
                    printf("(%d, %d): %.2f\t", atual->linha, atual->coluna, atual->valor);
                    z = 1;
                    break;}
                atual = atual->direita;}
            if (!z) {  printf("(0, 0): 0.00\t");}}
    }
}


Matriz lerMatriz(FILE *arquivo){
    Matriz matriz;
    int m, n;
    fscanf(arquivo, "%d, %d", &m, &n);

    matriz.nlin = m;
    matriz.ncol = n;
    matriz.cabeca = criar(-1, -1, 0.0);

    int i, j;
    float valor;
    while (fscanf(arquivo, "%d, %d, %f", &i, &j, &valor) == 3){
        inserir(&matriz, i, j, valor);}

    return matriz;}

Matriz somar(Matriz A, Matriz B){
    Matriz C;
    C.nlin = A.nlin;
    C.ncol = A.ncol;
    C.cabeca = criar(-1, -1, 0.0);

    for (int i = 1; i <= A.nlin; i++){
        for (int j = 1; j <= A.ncol; j++){
            float soma = 0.0;

            Celula *celulaA = A.cabeca->direita;
            Celula *celulaB = B.cabeca->direita;

            while (celulaA != A.cabeca || celulaB != B.cabeca){
                if (celulaA->linha == i && celulaA->coluna == j){
                    soma += celulaA->valor;
                    celulaA = celulaA->direita;}
                else if (celulaB->linha == i && celulaB->coluna == j){
                    soma += celulaB->valor;
                    celulaB = celulaB->direita;}
                    else{
                    if (celulaA->linha == i){
                        celulaA = celulaA->direita;}
                    if (celulaB->linha == i){
                        celulaB = celulaB->direita;}}
            }

            if (soma != 0.0){
               inserir(&C, i, j, soma);}
        }}
    return C;}

Matriz multiplicar(Matriz A, Matriz B){
    Matriz C;
    C.nlin = A.nlin;
    C.ncol = B.ncol;
    C.cabeca = criar(-1, -1, 0.0);

    for (int i = 1; i <= A.nlin; i++){
        for (int j = 1; j <= B.ncol; j++){
            float produto = 0.0;

            for (int k = 1; k <= A.ncol; k++){
                Celula *celulaA = A.cabeca->direita;
                Celula *celulaB = B.cabeca->direita;

                while (celulaA != A.cabeca && celulaA->coluna <= k){
                    if (celulaA->linha == i) {
                        while (celulaB != B.cabeca && celulaB->linha <= k){
                            if (celulaB->coluna == j){
                                produto += celulaA->valor * celulaB->valor;}
                            celulaB = celulaB->abaixo;}}
                    celulaA = celulaA->direita;}
            }

            if (produto != 0.0){
                inserir(&C, i, j, produto);}}}
    return C;
}

void deletar(Matriz *matriz){
    Celula *atual = matriz->cabeca->abaixo;

    while (atual != matriz->cabeca){
        Celula *proximaLinha = atual->abaixo;
        Celula *celulaAtual = atual->direita;

        while (celulaAtual != atual){
            Celula *proximaCelula = celulaAtual->direita;
            free(celulaAtual);
            celulaAtual = proximaCelula;}

        free(atual);
        atual = proximaLinha;
    }
    free(matriz->cabeca);
    matriz->cabeca = NULL;
}