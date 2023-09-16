#include <stdio.h>
#include <string.h>

int comparacoes = 0;
int mexidas = 0;

void quicksort(char *frutas[], int inicio, int final)
{
    if (inicio < final)
    {
        int pivo = particao(frutas, inicio, final);

        quicksort(frutas, inicio, pivo - 1);
        quicksort(frutas, pivo + 1, final);
    }
}

void troca(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
    mexidas++;
}

int particao(char *frutas[], int inicio, int final)
{
    char *pivo = frutas[final];
    int i = (inicio - 1);

    for (int j = inicio; j <= final - 1; j++)
    {
        comparacoes++;
        if (strcmp(frutas[j], pivo) < 0)
        {
            i++;
            troca(&frutas[i], &frutas[j]);
        }
    }
    troca(&frutas[i + 1], &frutas[final]);
    return (i + 1);
}

int main()
{
    char *frutas[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi", "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"};

    int n = sizeof(frutas) / sizeof(frutas[0]);

    quicksort(frutas, 0, n - 1);

    printf("\nVetor de palavras ordenado em ordem crescente:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", frutas[i]);
    }

    printf("Comparacaes: %d\n", comparacoes);
    printf("Trocas: %d\n", mexidas);

    //////////////////////////////////////////////////////////////////////////////////////
    int mediana_aux = n / 2;

    if (n % 2 == 0)
    {

        char *mediana1 = frutas[mediana_aux - 1];
        char *mediana2 = frutas[mediana_aux];

        printf("Mediana: %s e %s\n", mediana1, mediana2);
    }
    else
    {

        char *mediana = frutas[mediana_aux];
        printf("Mediana: %s\n", mediana);
    }

    ///////////////////////////////////////////////////////////////////////

    FILE *arquivo_saida = fopen("saida.txt", "w");

    if (arquivo_saida == NULL)
    {
        printf("Erro ao abrir o arquivo de saída.\n");
        exit(1);
    }

    fprintf(arquivo_saida, "Vetor de palavras ordenado em ordem crescente:\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(arquivo_saida, "%s\n", frutas[i]);
    }

    int medianaaux = n / 2;

    if (n % 2 == 0)
    {

        char *mediana1 = frutas[medianaaux - 1];
        char *mediana2 = frutas[medianaaux];

        fprintf(arquivo_saida, "Mediana: %s e %s\n", mediana1, mediana2);
    }
    else
    {
        char *mediana = frutas[medianaaux];
        fprintf(arquivo_saida, "Mediana: %s\n", mediana);
    }

    fprintf(arquivo_saida, "Comparações: %d\n", comparacoes);
    fprintf(arquivo_saida, "Trocas: %d\n", mexidas);

    fclose(arquivo_saida);
}
