
#define MATRIZ

typedef struct Celula {
    struct Celula *direita, *abaixo;
    int linha, coluna;
    float valor;
} Celula;

typedef struct {
    Celula *cabeca;
    int nlin, ncol;
} Matriz;

void imprimir(Matriz A);
Matriz lerMatriz(FILE *arquivo);
Matriz somar(Matriz A, Matriz B);
Matriz multiplicar(Matriz A, Matriz B);
void inserir(Matriz *matriz, int i, int j, float v);
void deletar(Matriz *matriz);
