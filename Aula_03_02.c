#include <stdio.h>

int main(){
    int V1;
    printf("Digite um valor:");
    scanf("%d", &V1);

    int V2;
    printf("Digite um valor:");
    scanf("%d", &V2);

    int V3;
    printf("Digite um valor:");
    scanf("%d", &V3);

    int soma = V1 + V2 + V3;
    printf("O valor total dos tres itens somados e %d", soma);
    return 0;
}