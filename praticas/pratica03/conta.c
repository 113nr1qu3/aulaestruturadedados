#include "conta.h"
#include <stdlib.h>

struct Conta {
    int numero;
    double saldo;
};

static int proximo_numero = 1;

Conta* conta_criar(double saldo_inicial) {
    Conta* conta = (Conta*)malloc(sizeof(Conta));
    if (conta != NULL) {
        conta->numero = proximo_numero++;
        conta->saldo = saldo_inicial;
    }
    return conta;
}

void conta_depositar(Conta* conta, double valor) {
    if (conta != NULL && valor > 0) {
        conta->saldo += valor;
    }
}

int conta_sacar(Conta* conta, double valor) {
    if (conta != NULL && valor > 0 && conta->saldo >= valor) {
        conta->saldo -= valor;
        return 1;
    }
    return 0;
}

double conta_ver_saldo(Conta* conta) {
    if (conta != NULL) {
        return conta->saldo;
    }
    return 0.0;
}

void conta_destruir(Conta* conta) {
    if (conta != NULL) {
        free(conta);
    }
}