#include <stdio.h>

int main(){
    int idade;

    do
    {
        printf("Digite a idade: ");
        scanf("%d", &idade);

        if(idade < 0 || idade > 120) {
            printf("Idade invalida, tente novamente!\n");
        }
    } while (idade < 0 || idade > 120);
    

    return 0;
}