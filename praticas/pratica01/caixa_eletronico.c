#include <stdio.h>

int main() {
    int valor, notas;
    int cedulas[] = {200, 100, 50, 20, 10, 5, 2};

    printf("Digite o valor do saque (Máx R$ 1000): ");
    scanf("%d", &valor);

    if (valor > 1000 || valor < 0) {
        printf("Valor inválido para saque.\n");

        return 0;
    }

    return 0;
}

