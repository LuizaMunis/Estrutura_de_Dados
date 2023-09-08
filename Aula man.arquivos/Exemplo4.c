#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE *arquivo;
    char linha[100];

    arquivo = fopen ("dados.txt","r");
    
    if(arquivo == NULL){
        printf("Erro\n");
        exit(1);
    }

    //le todas as linhas
    while(fgets(linha, sizeof(linha),arquivo)!=NULL){
        printf("%s", linha);
    }

    fclose(arquivo);

    return 0;
}