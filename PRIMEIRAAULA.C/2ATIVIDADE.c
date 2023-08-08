#include <stdio.h>

int sequenciaf (int N){
    if(N==1) return 1;
    else if (N==2) return 1;
    else return sequenciaf ( N-1) + sequenciaf(N-2);

}

int main(){
    int N;

    printf("Digite um numero:");
    scanf("%d",&N);
    printf("Resultado:%d",sequenciaf(N));
} 