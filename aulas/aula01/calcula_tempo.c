#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // ligou o cronometro
    clock_t tempo_inicial = clock();

    long int soma = 10 + 20; // 0(1)

    //desligou o cronometro
    clock_t tempo_final = clock();

    float duracao = (float) (tempo_final - tempo_inicial) 
        / CLOCKS_PER_SEC;

    printf("O tempo de execucao foi %.5lf seg", duracao);

    tempo_inicial = clock();

    //0(N^2)
    for (longint i=0; i<100000; i++) { 
        for (int j=0; j<100000; j++) {
            soma = soma + 1;
        }
    } 

    tempo_final = clock();

    duracao = (float) (tempo_final - tempo_inicial) 
        / CLOCKS_PER_SEC;

    printf("O tempo de execucao foi %.5lf seg", duracao);

    return 0;
}