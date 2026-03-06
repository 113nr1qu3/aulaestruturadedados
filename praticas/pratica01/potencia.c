#include <stdio.h>

int main() {
    int base = 1;
    int expoente = 0;
    long long resultado = 1;
    int i;

    printf("Digite a base: ");
    scanf("%d", &base);

    printf("Digite o expoente: ");
    scanf("%d", &expoente);

    for (i = 0; i < expoente; i++) {
        resultado *= base;
    }

    printf("O resultado é: %d\n", resultado);

    return 0;
}