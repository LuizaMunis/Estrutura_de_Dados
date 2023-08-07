#include <stdio.h>

int fatorial (int N){
    if (N==0) return 1;
    else return N*fatorial(n-1);
}

int main(){
    int N;
    printf("Digite um numero:");
    scanf("%d",&N);
    printf("Resultado:%d",fatorial(N));
    return;
}