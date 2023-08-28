#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main (){
    struct timeval inicio, final;
    double elapsed_time;
    gettimeofday(&inicio, NULL);

    gettimeofday(&final, NULL);

    elapsed_time= (final.tv.sec - inicio.tv.sec)+
                    (final.tv_usec - inicio.tv_usec)/1000000.0;
    printf("Tempo pecorrido:f", elapsed_time);
    return 0 ;                
}