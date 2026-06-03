#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

// Nó da lista
typedef struct no_t {
    struct no_t *anterior;
    int valor;
    struct no_t *proximo;
} No;

// Estrutura da lista
struct lista_t {
    No *primeiro;
    No *ultimo;
};

// Criar lista
Lista* lista_criar() {
    Lista *lista = (Lista*) malloc(sizeof(Lista));

    if (lista != NULL) {
        lista->primeiro = NULL;
        lista->ultimo = NULL;
    }

    return lista;
}

// Verifica se está vazia
int lista_esta_vazia(Lista *lista) {
    return (lista->primeiro == NULL);
}

// Inserir no final
void lista_inserir(Lista *lista, int valor) {

    No *novo = (No*) malloc(sizeof(No));

    if (novo == NULL)
        return;

    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = lista->ultimo;

    if (lista_esta_vazia(lista)) {
        lista->primeiro = novo;
        lista->ultimo = novo;
    }
    else {
        lista->ultimo->proximo = novo;
        lista->ultimo = novo;
    }
}

// Buscar valor
int lista_buscar(Lista *lista, int valor) {

    No *atual = lista->primeiro;

    while (atual != NULL) {

        if (atual->valor == valor)
            return 1;

        atual = atual->proximo;
    }

    return 0;
}

// Remover valor
int lista_remover(Lista *lista, int valor) {

    No *atual = lista->primeiro;

    while (atual != NULL && atual->valor != valor)
        atual = atual->proximo;

    if (atual == NULL)
        return 0;

    if (atual->anterior != NULL)
        atual->anterior->proximo = atual->proximo;
    else
        lista->primeiro = atual->proximo;

    if (atual->proximo != NULL)
        atual->proximo->anterior = atual->anterior;
    else
        lista->ultimo = atual->anterior;

    free(atual);

    return 1;
}

// Exibir lista
void lista_exibir(Lista *lista) {

    No *atual = lista->primeiro;

    printf("Lista: ");

    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }

    printf("\n");
}

// Destruir lista
void lista_destruir(Lista *lista) {

    No *atual = lista->primeiro;

    while (atual != NULL) {

        No *temp = atual;
        atual = atual->proximo;

        free(temp);
    }

    free(lista);
}