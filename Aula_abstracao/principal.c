#include<stdio.h>
#include<stdlib.h>
#include"Fracao.h"

int main(){

    fracao f=criarFracao(8,12)
    printf("%d/%d",f.numerador,f.denominador);
    return 0;
}