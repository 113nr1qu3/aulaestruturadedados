#include <stdio.h>
#include "pilha.h"

int main() {

    Pilha *pilha = pilha_criar();

    printf("Empilhando elementos...\n");

    pilha_empilhar(pilha, 10);
    pilha_empilhar(pilha, 20);
    pilha_empilhar(pilha, 30);
    pilha_empilhar(pilha, 40);

    pilha_exibir(pilha);

    printf("\nElemento do topo: %d\n",
           pilha_topo(pilha));

    printf("\nDesempilhando...\n");

    printf("Removido: %d\n",
           pilha_desempilhar(pilha));

    pilha_exibir(pilha);

    printf("\nNovo topo: %d\n",
           pilha_topo(pilha));

    printf("\nA pilha está vazia? ");

    if (pilha_esta_vazia(pilha))
        printf("Sim\n");
    else
        printf("Nao\n");

    pilha_destruir(pilha);

    return 0;
}
