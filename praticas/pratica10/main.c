#include <stdio.h>
#include "tabela_hash.h"

int main() {

    TabelaHash *hash = hash_criar(10);

    printf("Inserindo elementos...\n");

    hash_inserir(hash, 15);
    hash_inserir(hash, 25);
    hash_inserir(hash, 35);
    hash_inserir(hash, 42);
    hash_inserir(hash, 52);

    hash_exibir(hash);

    printf("\nBuscando 25...\n");

    if (hash_buscar(hash, 25))
        printf("Elemento encontrado!\n");
    else
        printf("Elemento nao encontrado!\n");

    printf("\nRemovendo 25...\n");

    if (hash_remover(hash, 25))
        printf("Elemento removido!\n");
    else
        printf("Elemento nao encontrado!\n");

    printf("\nTabela apos remocao:\n");
    hash_exibir(hash);

    printf("\nTabela vazia? ");

    if (hash_esta_vazia(hash))
        printf("Sim\n");
    else
        printf("Nao\n");

    hash_destruir(hash);

    return 0;
}