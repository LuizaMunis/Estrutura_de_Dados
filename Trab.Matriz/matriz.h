#define MATRIZ

typedef struct Celula
{
    struct Celula *direita, *abaixo;
    int linha, coluna;
    float valor;
} Celula;

typedef struct
{
    Celula *cabeca;
    int nlin, ncol;
} Matriz;

Matriz lerMatriz(FILE *arquivo);

void imprimir(Matriz A);

void inserir(Matriz *matriz, int i, int j, float v);

void deletar(Matriz *matriz);

Matriz somar(Matriz A, Matriz B);

Matriz multiplicar(Matriz A, Matriz B);
