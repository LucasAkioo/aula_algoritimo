#include <stdio.h> 

int main(){
    float numero;
    float soma = 0;
    float total = 0;

    printf("Digite um numero: ");
    scanf("%f", &numero);

    while (numero > 0){
        soma = soma + numero;
        total = total + 1;
        
        printf("Digite um numero: ");
        scanf("%f", &numero);
    }

        if (total == 0){ 
            printf("Nao foi entrado nenhum numero!");
        } else {
            if (total == 1) {
                printf("\nFoi inserido %.0f numero", total);
            } else{
                printf("\nForam inseridos %0.f numeros", total);
                printf("\nA media dos numeros entrados e: %f", soma/total);
            }
        }

    return 0;
}