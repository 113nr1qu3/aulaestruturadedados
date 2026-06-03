#ifndef CONTA_H
#define CONTA_H

typedef struct Conta Conta;

Conta* conta_criar(double saldo_inicial);
void conta_depositar(Conta* conta, double valor);
int conta_sacar(Conta* conta, double valor);
double conta_ver_saldo(Conta* conta);
void conta_destruir(Conta* conta);

#endif

