#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int fatorialSemRecursao(int n) {
    int resultado = 1;

    for (int i = 1; i <= n; i++) {
        resultado *= i; // multiplica o acumulador pelo valor atual de i
    }

    return resultado;
}

int fatorialComRecursao(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * fatorialComRecursao(n - 1);
    }
}

int main() {
    system("chcp 65001 > nul"); // configura o console para UTF-8
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int numero;

    printf("Digite um número para calcular o fatorial: ");
    scanf("%d", &numero);

    printf("O número digitado foi %d\n", numero);
    printf("O resultado do fatorial desse número é %d\n", fatorialSemRecursao(numero));

    return 0;
}