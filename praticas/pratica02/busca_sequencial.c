#include <stdio.h>

int main() {
    int arr[100];
    for(int i = 1; i < 100; i++) {
        arr[i] = i;
    }

    int target;
    printf("Digite o valor a ser procurado: ");
    scanf("%d", &target);

    // Busca sequencial
    for(int i = 0; i < 100; i++) {
        if(arr[i] == target) {
            printf("Valor encontrado na posição %d\n", i);
            return 0;
        }
    }

    printf("Valor não encontrado\n");

    // Complexidade assintótica:
    // Melhor caso: O(1) - quando o elemento está na primeira posição
    // Pior caso: O(n) - quando o elemento está na última posição ou não está presente

    return 0;
}
