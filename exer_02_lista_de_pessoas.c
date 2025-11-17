#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int idade;
    float altura;
    struct Pessoa *prox;
};

struct Pessoa *inicio = NULL;

// Inserir no início
void inserirInicio(char nome[], int idade, float altura) {
    struct Pessoa *novo = (struct Pessoa*) malloc(sizeof(struct Pessoa));
    strcpy(novo->nome, nome);
    novo->idade = idade;
    novo->altura = altura;

    novo->prox = inicio;
    inicio = novo;
}

// Inserir no fim
void inserirFim(char nome[], int idade, float altura) {
    struct Pessoa *novo = (struct Pessoa*) malloc(sizeof(struct Pessoa));
    strcpy(novo->nome, nome);
    novo->idade = idade;
    novo->altura = altura;
    novo->prox = NULL;

    if (inicio == NULL) {
        inicio = novo;
    } else {
        struct Pessoa *aux = inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

// Remover por nome
void removerPorNome(char nome[]) {
    struct Pessoa *atual = inicio;
    struct Pessoa *anterior = NULL;

    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Pessoa nao encontrada!\n");
        return;
    }

    if (anterior == NULL) {
        inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("Pessoa removida!\n");
}

// Mostrar todos
void mostrarTodos() {
    struct Pessoa *aux = inicio;

    if (aux == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    while (aux != NULL) {
        printf("Nome: %s | Idade: %d | Altura: %.2f\n",
               aux->nome, aux->idade, aux->altura);
        aux = aux->prox;
    }
}

int main() {
    int opcao;
    char nome[50];
    int idade;
    float altura;

    do {
        printf("\n1 - Inserir no inicio\n");
        printf("2 - Inserir no fim\n");
        printf("3 - Remover por nome\n");
        printf("4 - Mostrar todos\n");
        printf("5 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar();  // limpar ENTER

        if (opcao == 1) {
            printf("Nome: ");
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = 0;

            printf("Idade: ");
            scanf("%d", &idade);

            printf("Altura: ");
            scanf("%f", &altura);

            inserirInicio(nome, idade, altura);
        }

        else if (opcao == 2) {
            printf("Nome: ");
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = 0;

            printf("Idade: ");
            scanf("%d", &idade);

            printf("Altura: ");
            scanf("%f", &altura);

            inserirFim(nome, idade, altura);
        }

        else if (opcao == 3) {
            printf("Nome a remover: ");
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = 0;

            removerPorNome(nome);
        }

        else if (opcao == 4) {
            mostrarTodos();
        }

    } while (opcao != 5);

    return 0;
}