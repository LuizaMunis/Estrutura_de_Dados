#include<stdio.h>
#include "Fracao.h"

fracao criarFracao(int n, int d){
    fracao x;
    x.numerador=n;
    x.denominador=d;

    return x;
}