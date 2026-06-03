#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

// Nó da árvore
typedef struct no_t {
    struct no_t *esquerda;
    int valor;
    struct no_t *direita;
} No;

// Estrutura da árvore
struct arvore_t {
    No *raiz;
};

// Funções auxiliares
No* inserir_no(No *raiz, int valor);
void pre_ordem(No *raiz);
void em_ordem(No *raiz);
void pos_ordem(No *raiz);
void destruir_no(No *raiz);

// Criar árvore
Arvore* arvore_criar() {

    Arvore *arvore = (Arvore*) malloc(sizeof(Arvore));

    if (arvore != NULL)
        arvore->raiz = NULL;

    return arvore;
}

// Verifica se está vazia
int arvore_esta_vazia(Arvore *arvore) {
    return (arvore->raiz == NULL);
}

// Inserir elemento
void arvore_inserir(Arvore *arvore, int valor) {
    arvore->raiz = inserir_no(arvore->raiz, valor);
}

No* inserir_no(No *raiz, int valor) {

    if (raiz == NULL) {

        No *novo = (No*) malloc(sizeof(No));

        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;

        return novo;
    }

    if (valor < raiz->valor)
        raiz->esquerda = inserir_no(raiz->esquerda, valor);

    else if (valor > raiz->valor)
        raiz->direita = inserir_no(raiz->direita, valor);

    return raiz;
}

// Pré-ordem
void pre_ordem(No *raiz) {

    if (raiz != NULL) {

        printf("%d ", raiz->valor);

        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

void arvore_exibir_pre_ordem(Arvore *arvore) {

    pre_ordem(arvore->raiz);
    printf("\n");
}

// Em ordem
void em_ordem(No *raiz) {

    if (raiz != NULL) {

        em_ordem(raiz->esquerda);

        printf("%d ", raiz->valor);

        em_ordem(raiz->direita);
    }
}

void arvore_exibir_em_ordem(Arvore *arvore) {

    em_ordem(arvore->raiz);
    printf("\n");
}

// Pós-ordem
void pos_ordem(No *raiz) {

    if (raiz != NULL) {

        pos_ordem(raiz->esquerda);
        pos_ordem(raiz->direita);

        printf("%d ", raiz->valor);
    }
}

void arvore_exibir_pos_ordem(Arvore *arvore) {

    pos_ordem(arvore->raiz);
    printf("\n");
}

// Destruir árvore
void destruir_no(No *raiz) {

    if (raiz != NULL) {

        destruir_no(raiz->esquerda);
        destruir_no(raiz->direita);

        free(raiz);
    }
}

void arvore_destruir(Arvore *arvore) {

    destruir_no(arvore->raiz);

    free(arvore);
}