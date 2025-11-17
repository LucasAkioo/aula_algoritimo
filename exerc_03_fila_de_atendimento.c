#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int senha;
    struct Pessoa *prox;
};

struct Pessoa *inicio = NULL;
struct Pessoa *fim = NULL;
int contadorSenhas = 1;

// ---------------------------
// Enfileirar (inserir no fim)
// ---------------------------
void enfileirar(char nome[]) {
    struct Pessoa *novo = (struct Pessoa*) malloc(sizeof(struct Pessoa));

    strcpy(novo->nome, nome);
    novo->senha = contadorSenhas++;
    novo->prox = NULL;

    if (inicio == NULL) { 
        inicio = novo;
        fim = novo;
    } else {
        fim->prox = novo;
        fim = novo;
    }

    printf("Senha %d gerada para %s\n", novo->senha, novo->nome);
}

// ---------------------------
// Desenfileirar (remover do início)
// ---------------------------
void desenfileirar() {
    if (inicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    struct Pessoa *temp = inicio;
    printf("Chamando: %s (senha %d)\n", temp->nome, temp->senha);

    inicio = inicio->prox;

    if (inicio == NULL) {
        fim = NULL;
    }

    free(temp);
}

// ---------------------------
// Mostrar fila
// ---------------------------
void mostrarFila() {
    struct Pessoa *aux = inicio;

    if (aux == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    printf("\n--- FILA ATUAL ---\n");
    while (aux != NULL) {
        printf("Nome: %s | Senha: %d\n", aux->nome, aux->senha);
        aux = aux->prox;
    }
    printf("------------------\n");
}

int main() {
    int opcao;
    char nome[50];

    do {
        printf("\n1 - Gerar nova senha (enfileirar)\n");
        printf("2 - Chamar próxima pessoa (desenfileirar)\n");
        printf("3 - Mostrar fila atual\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpar ENTER

        if (opcao == 1) {
            printf("Nome: ");
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = 0;
            enfileirar(nome);
        }

        else if (opcao == 2) {
            desenfileirar();
        }

        else if (opcao == 3) {
            mostrarFila();
        }

    } while (opcao != 4);

    return 0;
}