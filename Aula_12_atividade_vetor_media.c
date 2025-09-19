#include <stdio.h>
#define TAM 5

int main(){
    int valores[TAM];
    int soma = 0;
    float media;

    printf("\nO sistema ira pedir 5 notas ");
    for (int i = 0; i < TAM; i++)
    {
        printf("\nDigite a nota do aluno: ");
        scanf("%d", &valores[i]);
    }

    printf("As notas sao: ");
    for (int i = 0; i < TAM; i++)
    {
        printf("%d ", valores[i]);
        soma+= valores[i];
    }

    media = soma/TAM;
    printf("\nA media das notas e: %0.2f", media);

    return 0;
}