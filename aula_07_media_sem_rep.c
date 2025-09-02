#include <stdio.h>

int main(){
    float valor_a, valor_b, valor_c, media;
    int contador = 1;

    while (contador == 1){
        printf("Digite tres valores: ");
        scanf("%f %f %f", &valor_a, &valor_b, &valor_c);

        media = (valor_a + valor_b + valor_c) / 3;
        printf("Sua media e: %f\n", media);

        printf("Digite 0 para terminar e 1 para continuar: ");
        scanf("%d", &contador);
    }

    printf("Fim do programa!\n");

    return 0;
}