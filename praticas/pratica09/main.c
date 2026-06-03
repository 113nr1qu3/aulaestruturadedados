#include <stdio.h>
#include "arvore_binaria.h"

int main() {

    Arvore *arvore = arvore_criar();

    printf("Inserindo elementos...\n");

    arvore_inserir(arvore, 50);
    arvore_inserir(arvore, 30);
    arvore_inserir(arvore, 70);
    arvore_inserir(arvore, 20);
    arvore_inserir(arvore, 40);
    arvore_inserir(arvore, 60);
    arvore_inserir(arvore, 80);

    printf("\nPercurso Pre-Ordem:\n");
    arvore_exibir_pre_ordem(arvore);

    printf("\nPercurso Em Ordem:\n");
    arvore_exibir_em_ordem(arvore);

    printf("\nPercurso Pos-Ordem:\n");
    arvore_exibir_pos_ordem(arvore);

    printf("\nArvore vazia? ");

    if (arvore_esta_vazia(arvore))
        printf("Sim\n");
    else
        printf("Nao\n");

    arvore_destruir(arvore);

    return 0;
}