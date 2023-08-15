#include <stdio.h>
//passagem por referencia

void modificaArray(int *array, int tamanho){
    for(int i=0;i<tamanho;i++){
        array[i]=array[i]*2;
      printf("%d\t", array[i]);}
}

int main(){
    
    int meuArray[]={2,5,6,9,0};
    int tamanho=sizeof(meuArray)/sizeof(meuArray[0]);

    modificaArray(meuArray,tamanho);

    return 0;
}