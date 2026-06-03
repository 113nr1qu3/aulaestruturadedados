#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

// Nó da lista encadeada
typedef struct no_t {
    int valor;
    struct no_t *proximo;
} No;

// Estrutura da tabela hash
struct hash_t {
    No **tabela;
    int tamanho;
};

// Função hash
int funcao_hash(TabelaHash *hash, int valor) {
    return valor % hash->tamanho;
}

// Criar tabela hash
TabelaHash* hash_criar(int tamanho) {

    TabelaHash *hash = (TabelaHash*) malloc(sizeof(TabelaHash));

    if (hash == NULL)
        return NULL;

    hash->tamanho = tamanho;

    hash->tabela = (No**) calloc(tamanho, sizeof(No*));

    return hash;
}

// Verificar se está vazia
int hash_esta_vazia(TabelaHash *hash) {

    for (int i = 0; i < hash->tamanho; i++) {
        if (hash->tabela[i] != NULL)
            return 0;
    }

    return 1;
}

// Inserir elemento
void hash_inserir(TabelaHash *hash, int valor) {

    int indice = funcao_hash(hash, valor);

    No *novo = (No*) malloc(sizeof(No));

    novo->valor = valor;
    novo->proximo = hash->tabela[indice];

    hash->tabela[indice] = novo;
}

// Buscar elemento
int hash_buscar(TabelaHash *hash, int valor) {

    int indice = funcao_hash(hash, valor);

    No *atual = hash->tabela[indice];

    while (atual != NULL) {

        if (atual->valor == valor)
            return 1;

        atual = atual->proximo;
    }

    return 0;
}

// Remover elemento
int hash_remover(TabelaHash *hash, int valor) {

    int indice = funcao_hash(hash, valor);

    No *atual = hash->tabela[indice];
    No *anterior = NULL;

    while (atual != NULL) {

        if (atual->valor == valor) {

            if (anterior == NULL)
                hash->tabela[indice] = atual->proximo;
            else
                anterior->proximo = atual->proximo;

            free(atual);

            return 1;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    return 0;
}

// Exibir tabela
void hash_exibir(TabelaHash *hash) {

    printf("Tabela Hash:\n");

    for (int i = 0; i < hash->tamanho; i++) {

        printf("[%d] -> ", i);

        No *atual = hash->tabela[i];

        while (atual != NULL) {

            printf("%d -> ", atual->valor);
            atual = atual->proximo;
        }

        printf("NULL\n");
    }
}

// Destruir tabela
void hash_destruir(TabelaHash *hash) {

    for (int i = 0; i < hash->tamanho; i++) {

        No *atual = hash->tabela[i];

        while (atual != NULL) {

            No *temp = atual;

            atual = atual->proximo;

            free(temp);
        }
    }

    free(hash->tabela);
    free(hash);
}