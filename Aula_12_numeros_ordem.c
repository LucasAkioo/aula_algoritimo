#include <stdio.h>
#define TAM 5

int main(){
    int numeros[TAM];

    printf("\nOla! O sistema ira pedir 5 numeros: ");
    for (int i = 0; i <= TAM; i++)
    {
        printf("Escreva um numero: ");
        scanf("%d", &numeros);
    }
    

    return 0;
}