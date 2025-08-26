#include <stdio.h>

int main() {
    float nota;
    int faltas;

    printf("Qual foi a sua nota?");
    scanf("%f", &nota);
    printf("Quantas faltas voce teve?");
    scanf("%d", &faltas);

    if (nota>=9 && faltas < 20){
        printf("Aprovado!");
    } else if (nota>=7 && faltas<= 15){
        printf("Aprovado!");
    } else if(nota>=5 || faltas> 15) {
        printf("Recuperacao!");
    } else if(nota<5 || faltas>20) {
        printf("Reprovado!");
    }

    return 0;
}