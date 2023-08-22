#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    __FILE__ * arquivo;

    int quantidade;
    int contador=0;
    char produto[50];
    float total=0;
    float preco;
    float subtotal;

    arquivo = fopen("sos.txt","r");

      if(arquivo == NULL){
        printf("Erro\n");
        exit(1);
    }

    while(fscanf(arquivo,"%s %d %f", produto,&quantidade,&preco)!= EOF){
        contador++;
        subtotal=quantidade*preco;
        total=total+subtotal;
        printf("%d\t %s\t %d\t%2.f\n",contador,produto,quantidade,preco,subtotal);
    }

    printf("Ovalor da compra e :%2.f",total);
     
       fclose(arquivo);

    return 0;
}