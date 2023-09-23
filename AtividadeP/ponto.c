#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "ponto.h"

double calcularArea(Ponto pontos[], int n) {
    double area = 0.0;

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += (pontos[i].X * pontos[j].Y) - (pontos[j].X * pontos[i].Y);
    }

    return 0.5 * fabs(area);
}

int lerVertices(const char *Arquivo, Ponto pontos[], int *n) {
    FILE *file;
    
    file = fopen("C:\\Users\\luiza\\Estrutura de dados\\Estrutura_de_Dados\\AtividadeP\\vertices.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    fscanf(file, "%d", n);

    for (int i = 0; i < *n; i++) {
        fscanf(file, "%f %f", &pontos[i].X, &pontos[i].Y);
    }
    fclose(file);

    return 1;
}
