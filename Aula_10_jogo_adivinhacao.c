#include <stdio.h> 

int main(){
    int n, n2;

    printf("Digite um numero: ");
    scanf("%d", &n);

    do
    {
        printf("Adivinhe o numero: ");
        scanf("%d", &n2);

        if (n2 > n)
        {
            printf("O numero escolhido esta mais para baixo\n");
        } else if(n2 < n){
            printf("O numero escolhido esta mais para cima\n");
        } else if(n2 == n) {
            printf("Parabens! Voce acertou o numero!");
        }
        
    } while (n != n2);
    
    

    return 0;
}