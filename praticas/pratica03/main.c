#include <stdio.h>
#include "conta.h"

int main() {
    // Criar uma conta com saldo inicial de 100.0
    Conta* conta = conta_criar(100.0);
    if (conta == NULL) {
        printf("Erro ao criar conta.\n");
        return 1;
    }

    // Verificar saldo inicial
    printf("Saldo inicial: %.2f\n", conta_ver_saldo(conta));

    // Depositar 50.0
    conta_depositar(conta, 50.0);
    printf("Apos deposito de 50.0: %.2f\n", conta_ver_saldo(conta));

    // Sacar 30.0
    if (conta_sacar(conta, 30.0)) {
        printf("Saque de 30.0 realizado. Saldo: %.2f\n", conta_ver_saldo(conta));
    } else {
        printf("Saque de 30.0 falhou.\n");
    }

    // Tentar sacar 200.0 (deve falhar)
    if (conta_sacar(conta, 200.0)) {
        printf("Saque de 200.0 realizado. Saldo: %.2f\n", conta_ver_saldo(conta));
    } else {
        printf("Saque de 200.0 falhou. Saldo insuficiente.\n");
    }

    // Verificar saldo final
    printf("Saldo final: %.2f\n", conta_ver_saldo(conta));

    // Destruir a conta
    conta_destruir(conta);

    return 0;
}