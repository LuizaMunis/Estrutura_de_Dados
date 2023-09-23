#define PONTO

typedef struct {
    float X;
    float Y;
} Ponto;

double calcularArea(Ponto pontos[], int n);
int lerVertices(const char *Arquivo, Ponto pontos[], int *n);
