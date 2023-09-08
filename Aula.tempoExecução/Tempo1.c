#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int fibonacci(int n){
    if (n==1)return 1;
    if(n==2)return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}

int main (){

    clock_t inicio, final;
    double tempo;

    inicio=clock();
    int x =fibonacci(50);
    final=clock();

    tempo=((double) (final-inicio))/CLOCKS_PER_SEC;

    printf("Termo da serie:%d\n",x);
    printf("Tempo de execucao:%f", tempo);

    return 0;
}