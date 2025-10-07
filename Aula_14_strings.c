#include <stdio.h>

int main(){
    char nome[20];
    char sobrenome[20];
    char completo[30];

    printf("Digite o seu primeiro nome: ");
    scanf("%s", nome);

    printf("Digite o seu sobrenome: ");
    scanf("%s", sobrenome);

    strcpy(completo, nome);
    strcat(completo, " ");
    strcat(completo, sobrenome);

    printf("\nO primeiro nome: %s", nome);
    printf("\nO sobrenome: %s", sobrenome);
    printf("\n Tamanho do nome: %d",strlen(completo));

    if (toupper(nome[0]) == 'A')
    {
        printf("\n Sim, inicia com A.");
    } else {
        printf("\n Nao inicia com A.");
    }

    printf("\n O seu nome completo e: %s",completo);
    

    return 0;
}