#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ponto.h"

int main()
{

    Ponto pontos[10];
    int n;

    lerVertices("C:\\Users\\luiza\\Estrutura de dados\\Estrutura_de_Dados\\AtividadeP\\vertices.txt", pontos, &n);
    double area = calcularArea(pontos, n);
    printf("A area do poligono e %.2lf\n", area);

    return 0;
}