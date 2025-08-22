#include <stdio.h>

int main(){
    float V1;
    printf("Digite um valor: ");
    scanf("%f", &V1);

    float V2;
    printf("Digite um valor: ");
    scanf("%f", &V2);

    float V3;
    printf("Digite um valor: ");
    scanf("%f", &V3);

    float soma = V1 + V2 + V3;
    float media = (V1 + V2 + V3) / 3;

    printf("A soma dos tres itens e %f\n", soma);
    printf("A media dos tres itens e %f", media);
    return 0;
}