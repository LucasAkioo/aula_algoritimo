#include <stdio.h>

int main(){
    int resposta = 1;
    float notaA, notaB;

    do {
        printf("Digite a nota A: ");
        scanf("%f", &notaA);

        printf("Digite a nota B: ");
        scanf("%f", &notaB);

        printf("A media das notas e %f\n", (notaA + notaB) / 2);
        printf("Deseja encerrar [0] ou calcular novamente [1]: ");
        scanf("%d", &resposta);
    } while (resposta == 1);

    return 0;
}