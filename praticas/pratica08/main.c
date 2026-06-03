#include <stdio.h>
#include "fila.h"

int main() {

    Fila *fila = fila_criar();

    printf("Enfileirando elementos...\n");

    fila_enfileirar(fila, 10);
    fila_enfileirar(fila, 20);
    fila_enfileirar(fila, 30);
    fila_enfileirar(fila, 40);

    fila_exibir(fila);

    printf("\nPrimeiro elemento da fila: %d\n",
           fila_inicio(fila));

    printf("\nDesenfileirando...\n");

    printf("Removido: %d\n",
           fila_desenfileirar(fila));

    fila_exibir(fila);

    printf("\nNovo inicio: %d\n",
           fila_inicio(fila));

    printf("\nA fila está vazia? ");

    if (fila_esta_vazia(fila))
        printf("Sim\n");
    else
        printf("Nao\n");

    fila_destruir(fila);

    return 0;
}