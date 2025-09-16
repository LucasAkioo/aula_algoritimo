#include <stdio.h>

int main(){
    int numero, quantidade = 0, maior = 0, soma = 0;
    float media;

    while (1) {
        printf("Digite um numero inteiro (0 para parar): ");
        scanf("%d", &numero);

        if (numero == 0)
            break;

        soma += numero;
        quantidade++;

        if (quantidade == 1 || numero > maior) {
            maior = numero;
        }
    }

    if (quantidade == 0) {
        maior = 0;
        media = 0.0;
    } else {
        media = (float)soma / quantidade;
    }


    printf("%d\n", quantidade);
    printf("%d\n", maior);
    printf("%.2f\n", media);

    return 0;
}