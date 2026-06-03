#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Nó da fila
typedef struct no_t {
    int valor;
    struct no_t *proximo;
} No;

// Estrutura da fila
struct fila_t {
    No *inicio;
    No *fim;
};

// Criar fila
Fila* fila_criar() {

    Fila *fila = (Fila*) malloc(sizeof(Fila));

    if (fila != NULL) {
        fila->inicio = NULL;
        fila->fim = NULL;
    }

    return fila;
}

// Verifica se está vazia
int fila_esta_vazia(Fila *fila) {
    return (fila->inicio == NULL);
}

// Enfileirar
void fila_enfileirar(Fila *fila, int valor) {

    No *novo = (No*) malloc(sizeof(No));

    if (novo == NULL)
        return;

    novo->valor = valor;
    novo->proximo = NULL;

    if (fila_esta_vazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    }
    else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
}

// Desenfileirar
int fila_desenfileirar(Fila *fila) {

    if (fila_esta_vazia(fila)) {
        printf("Fila vazia!\n");
        return -1;
    }

    No *remover = fila->inicio;

    int valor = remover->valor;

    fila->inicio = remover->proximo;

    if (fila->inicio == NULL)
        fila->fim = NULL;

    free(remover);

    return valor;
}

// Consultar início
int fila_inicio(Fila *fila) {

    if (fila_esta_vazia(fila)) {
        printf("Fila vazia!\n");
        return -1;
    }

    return fila->inicio->valor;
}

// Exibir fila
void fila_exibir(Fila *fila) {

    No *atual = fila->inicio;

    printf("Inicio -> ");

    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }

    printf("<- Fim\n");
}

// Destruir fila
void fila_destruir(Fila *fila) {

    while (!fila_esta_vazia(fila)) {
        fila_desenfileirar(fila);
    }

    free(fila);
}