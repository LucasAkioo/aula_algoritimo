#include <stdio.h> 

int main(){
    int La, Lb, Lc;

    printf("Digite o lado A: ");
    scanf("%d", &La);
    printf("Digite o lado B: ");
    scanf("%d", &Lb);
    printf("Digite o lado C: ");
    scanf("%d", &Lc);

    if(La>Lb+Lc && Lb < La + Lc && Lc < La + Lb){
        if (La == Lb == Lc) {
            printf("Esse e um triangulo Equilatero");
        } else if(La == Lb && Lb != Lc){
            printf("Esse triangulo e Isósceles");
        } else if(La != Lb && Lb != Lc){
            printf("Esse triangulo e Isósceles");
        }

        printf("Nao e um triangulo");
    } 

    return 0;
}