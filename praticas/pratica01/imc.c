#include <stdio.h>

int main() {
    float peso, altura, imc;

    printf("Digite o peso (em kg): ");
    scanf("%f", &peso);

    printf("Digite a altura (em metros): ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    printf("O IMC é: %.2f\n", imc);

    if (imc < 18.5) {
        printf("Classificação: Abaixo do peso\n");
    } else if (imc >= 18.5 && imc < 25) {
        printf("Classificação: Peso normal\n");
    } else if (imc >= 25 && imc < 30) {
        printf("Classificação: Sobrepeso\n");
    } else { (imc >= 30);
        printf("Classificação: Obesidade\n");
    }
    return 0;
}
