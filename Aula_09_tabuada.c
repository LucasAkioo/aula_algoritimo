#include <stdio.h>

int main(){
    int numero, contador = 0;

    printf("Digite um numero: ");
    scanf("%d", &numero);


    while (contador <= 10)
    {
        printf("%d X %d = %d\n", numero, contador, numero * contador);
        contador ++;
    }
    

    return 0;
}