#ifndef FILA_H
#define FILA_H

typedef struct fila_t Fila;

// Criação
Fila* fila_criar();

// Operações
void fila_enfileirar(Fila *fila, int valor);
int fila_desenfileirar(Fila *fila);
int fila_inicio(Fila *fila);
int fila_esta_vazia(Fila *fila);
void fila_exibir(Fila *fila);

// Destruição
void fila_destruir(Fila *fila);

#endif