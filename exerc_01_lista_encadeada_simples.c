#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No *prox;
};

struct No *inicio = NULL;

// Inserir no início
void inserirInicio(int v) {
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->valor = v;
    novo->prox = inicio;
    inicio = novo;
}

// Inserir no fim
void inserirFim(int v) {
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    novo->valor = v;
    novo->prox = NULL;

    if (inicio == NULL) {
        inicio = novo;
    } else {
        struct No *aux = inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

// Remover por valor
void removerValor(int v) {
    struct No *atual = inicio;
    struct No *anterior = NULL;

    while (atual != NULL && atual->valor != v) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Valor nao encontrado!\n");
        return;
    }

    if (anterior == NULL) {
        inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("Valor removido!\n");
}

// Mostrar lista
void mostrarLista() {
    struct No *aux = inicio;

    printf("Lista: ");
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

int main() {
    int opcao, valor;

    do {
        printf("\n1 - Inserir no inicio\n");
        printf("2 - Inserir no fim\n");
        printf("3 - Remover por valor\n");
        printf("4 - Mostrar lista\n");
        printf("5 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Valor: ");
            scanf("%d", &valor);
            inserirInicio(valor);
        }

        else if (opcao == 2) {
            printf("Valor: ");
            scanf("%d", &valor);
            inserirFim(valor);
        }

        else if (opcao == 3) {
            printf("Valor a remover: ");
            scanf("%d", &valor);
            removerValor(valor);
        }

        else if (opcao == 4) {
            mostrarLista();
        }

    } while (opcao != 5);

    return 0;
}