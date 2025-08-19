#include <stdio.h>

int main(){
    int idade;
    printf("Digite a sua idade:");
    scanf("%d", &idade);

    printf("Sua idade e %d\n", idade);
    printf("Minha posicao de memoria e %d\n", &idade);
    return 0;
}