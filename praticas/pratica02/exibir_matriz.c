#include <stdio.h>
#include <time.h>

#define N 10

int main() {
    int matriz[N][N];

    // Inicializar a matriz com valores sequenciais
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            matriz[i][j] = i * N + j;
        }
    }

    // Método 1: Dois laços aninhados
    clock_t inicio1 = clock();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int tempo = matriz[i][j];
        }
    }
    clock_t fim1 = clock();
    double tempo1 = (double)(fim1 - inicio1) / CLOCKS_PER_SEC;

    // Método 2: Um único laço
    clock_t inicio2 = clock();
    for(int k = 0; k < N * N; k++) {
        int i = k / N;
        int j = k % N;
        int tempo = matriz[i][j];
    }
    clock_t fim2 = clock();
    double tempo2 = (double)(fim2 - inicio2) / CLOCKS_PER_SEC;

    printf("Tempo para laços aninhados: %f segundos\n", tempo1);
    printf("Tempo para laço único: %f segundos\n", tempo2);
    printf("Complexidade assintótica de ambas as soluções: O(N^2)\n");

    return 0;
}
