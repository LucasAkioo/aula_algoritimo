#include <stdio.h>

int main(){
    float v1, v2;
    float resultado;
    char operacao;

    printf("Digite valor 1: ");
    scanf("%f", &v1);
    printf("Digite valor 2: ");
    scanf("%f", &v2);

    printf("[S]Soma | [U]Subtracao | [M]Multiplicacao [D]Divisao\n");
    printf("Digite a operacao: ");
    scanf("%s", &operacao);

    if(operacao == 'S') {
        resultado = v1 + v2;
    } else if (operacao == 'U'){
        resultado = v1 - v2;
    } else if (operacao == 'M') {
        resultado = v1 * v2;
    } else if (operacao == 'D') {
        resultado = v1 / v2;
    }

    //Calculo das operacoes

    //Saida do valor
    printf("Meu resultado e %f", resultado);

    return 0;
}