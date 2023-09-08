#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Aluno
{
    char nome[50];
    double nota1;
    double nota2;
};

int main()
{
    char dados[200];
    struct Aluno aluno;
    int linha = 0;
    double media;

    FILE *arquivoLeitura, *arquivoFinal;

    arquivoLeitura = fopen("C:\\Users\\luiza\\Downloads\\DadosEntrada.csv", "r");
    arquivoFinal = fopen("C:\\Users\\luiza\\Downloads\\DadosFinais.csv", "w");

    if (arquivoLeitura == NULL || arquivoFinal == NULL)
    {
        printf("Erro ao abrir os arquivos.\n");
        exit(1);
    }

    fgets(dados, sizeof(dados), arquivoLeitura);

    while (fgets(dados, sizeof(dados), arquivoLeitura) != NULL)
    {
        char *token = strtok(dados, ",");
        
        if (token == NULL)
        {
            linha++;
            continue;
        }


        strcpy(aluno.nome, token);
        token = strtok(NULL, ",");

        token = strtok(NULL, ",");
        token = strtok(NULL, ",");

        sscanf(token, "%lf", &aluno.nota1);
        token = strtok(NULL, ",");
        sscanf(token, "%lf", &aluno.nota2);

        media = (aluno.nota1 + aluno.nota2) / 2.0;

        if (media >= 7.0)
        {
            fprintf(arquivoFinal, "%s, %.2lf, APROVADO\n", aluno.nome, media);
        }
        else
        {
            fprintf(arquivoFinal, "%s, %.2lf, REPROVADO\n", aluno.nome, media);
        }

        linha++;
    }

    fclose(arquivoLeitura);
    fclose(arquivoFinal);

    printf("Verifique o arquivo 'DadosFinais.csv'.\n");

    return 0;
}

