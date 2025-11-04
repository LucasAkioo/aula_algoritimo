#include <stdio.h>
#include <locale.h>

int potencia(int base, int exp) {
    if (exp == 0)
        return 1;
    else
        return base * potencia(base, exp - 1);
}

int main() {
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int base;
    int expoente;
    int resultado;

    printf("Insira um número: ");
    scanf("%d", &base);
    printf("Insira a potência para elevar o número inserido: ");
    scanf("%d", &expoente);

    resultado = potencia(base, expoente);

    printf("O resultado é: %d", resultado);

    return 0;
}