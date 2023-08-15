#include <stdio.h>

int main(){
    int soma=0;
    int matriz [2][3]={
        {1,2,3},
        {4,5,6}
    };

    printf("Elemento da 2a linha e 3a coluna:%d\n", matriz[1][2]);

    for(int i=0;i<2;i++)
       for(int j=0; j<3;j++)
        soma=soma+matriz[i][j];

    printf("Asoma dos elemntos e:%d", soma);
  
   
    return 0;
}