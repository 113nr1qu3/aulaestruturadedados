#include <stdio.h>

// Função recursiva para calcular fatorial
long long fatorial_recursivo(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * fatorial_recursivo(n - 1);
}

int main() {
    int n;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Numero deve ser positivo.\n");
        return 1;
    }

    // Cálculo iterativo
    long long fatorial_iterativo = 1;
    for (int i = 1; i <= n; i++) {
        fatorial_iterativo *= i;
    }

    // Cálculo recursivo
    long long fatorial_rec = fatorial_recursivo(n);

    // Complexidade assintótica:
    // Ambos os métodos têm complexidade O(n), pois envolvem
    // operacoes lineares em relacao ao valor de n.

    return 0;
}