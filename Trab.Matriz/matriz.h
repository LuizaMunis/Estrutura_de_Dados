
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


void inserir(Matriz *matriz, int i, int j, float v);
Matriz lerMatriz(FILE *arquivo);
void imprimir(Matriz A);
Matriz somar(Matriz A, Matriz B);
Matriz multiplicar(Matriz A, Matriz B);
void deletar(Matriz *matriz);
