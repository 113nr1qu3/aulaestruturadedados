#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Nó da pilha
typedef struct no_t {
    int valor;
    struct no_t *proximo;
} No;

// Estrutura da pilha
struct pilha_t {
    No *topo;
};

// Criar pilha
Pilha* pilha_criar() {

    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));

    if (pilha != NULL) {
        pilha->topo = NULL;
    }

    return pilha;
}

// Verificar se está vazia
int pilha_esta_vazia(Pilha *pilha) {
    return (pilha->topo == NULL);
}

// Empilhar
void pilha_empilhar(Pilha *pilha, int valor) {

    No *novo = (No*) malloc(sizeof(No));

    if (novo == NULL)
        return;

    novo->valor = valor;
    novo->proximo = pilha->topo;

    pilha->topo = novo;
}

// Desempilhar
int pilha_desempilhar(Pilha *pilha) {

    if (pilha_esta_vazia(pilha)) {
        printf("Pilha vazia!\n");
        return -1;
    }

    No *remover = pilha->topo;

    int valor = remover->valor;

    pilha->topo = remover->proximo;

    free(remover);

    return valor;
}

// Consultar topo
int pilha_topo(Pilha *pilha) {

    if (pilha_esta_vazia(pilha)) {
        printf("Pilha vazia!\n");
        return -1;
    }

    return pilha->topo->valor;
}

// Exibir pilha
void pilha_exibir(Pilha *pilha) {

    No *atual = pilha->topo;

    printf("Topo -> ");

    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }

    printf("\n");
}

// Destruir pilha
void pilha_destruir(Pilha *pilha) {

    while (!pilha_esta_vazia(pilha)) {
        pilha_desempilhar(pilha);
    }

    free(pilha);
}