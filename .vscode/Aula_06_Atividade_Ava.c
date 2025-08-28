#include <stdio.h>

int main(){
    float N1,N2,N3, media;
    int faltas;

    printf("Digite a primeira nota:");
    scanf("%f", &N1);
    printf("Digite a segunda nota:");
    scanf("%f", &N2);
    printf("Digite a terceira nota:");
    scanf("%f", &N3);
    printf("Quantas faltas?");
    scanf("%d", &faltas);

    media = (N1+N2+N3)/3;

    if(faltas > 18) {
        printf("Reprovado por faltas");
    } else if (media >=9 && faltas <=18){
        printf("SR\n");
    } else if (media >=7 && faltas <=18){
        printf("MS\n");
    } else if (media >=5 && faltas <=18){
        printf("MM\n");
    } else if (media >=3 && faltas <=18){
        printf("MI\n");
    } else if (media >=1 && faltas <=18){
        printf("II\n");
    }

    return 0;
}