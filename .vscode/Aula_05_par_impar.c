#include <stdio.h>

int main() {
    int valor_a;

    printf ("Digite um numero: ");
    scanf ("%d", &valor_a);

    if (valor_a % 2 == 0) {
        printf(" O valor A e PAR\n");
    } else {
        printf(" O valor A e IMPAR\n");
    }

    return 0;
}