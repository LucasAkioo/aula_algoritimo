#include <stdio.h>

int main() {
    float v1,v2;

    printf ("Digite um numero: ");
    scanf ("%f", &v1);
    printf ("Digite outro numero: ");
    scanf ("%f", &v2);

    if (v1>v2){
        printf("O valor 1 e maior que o valor 2");
    } else if (v1==v2){
        printf("Os valores sao iguais");
    } else {
        printf("O valor 2 e maior que o valor 1");
    }

    return 0;
}