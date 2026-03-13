#include <stdio.h>

int main() {
    float valor, saque, saldo;
    printf("Digite o valor do saque: ");
    scanf("%f", &saque);

    printf("Digite o saldo disponível: ");
    scanf("%f", &saldo);

    if (saque > saldo) {
        printf("Saldo insuficiente para realizar o saque.\n");
    } else {
        valor = saldo - saque;
        printf("Saque realizado com sucesso. Saldo restante: %.2f\n", valor);
    }

}


