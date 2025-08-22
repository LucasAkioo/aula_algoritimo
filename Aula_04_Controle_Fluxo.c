#include <stdio.h>

int main(){
    int idade;
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    if(idade>=24){
        printf("Voce e um adulto formado");
    } else if(idade>=18){
        printf("Voce e maior de idade");
    } else{
        printf("Voce e menor de idade");
    }

    return 0;
}