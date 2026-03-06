#include <stdio.h>

int main() {
    int n, i;
    float soma = 0.0, media;

    printf("Digite a quantidade de números: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        float num;
        printf("Digite o número %d: ", i + 1);
        scanf("%f", &num);
        soma += num;
    }

    media = soma / n;
    printf("A média aritmética é: %.2f\n", media);

    return 0;
}

