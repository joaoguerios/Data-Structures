/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Bloco {
    int dado;
    struct Bloco *prox;
} Nodo;
Nodo *lista = NULL;
Nodo* Cria_Nodo_fila() {
    Nodo *p;
    p = (Nodo*) malloc(sizeof(Nodo));
    return p;
}
void push_fila(Nodo **N, int dado) {
    Nodo *novo = Cria_Nodo_fila();
    novo->dado = dado;
    novo->prox = NULL;
    if (*N == NULL) {
        *N = novo;
    } else {
        Nodo *temp = *N;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}
void pop_fila(Nodo **N) {
    if (*N == NULL) {
        printf("Lista vazia, impossível remover.\n");
        return;
    }
    Nodo *temp = *N;
    *N = (*N)->prox;
    free(temp);
}
void show_fila(Nodo *lista) {
    if (!lista) {
        printf("A lista esta vazia!\n");
        return;
    }
    Nodo *temp = lista;
    while (temp != NULL) {
        printf("%d ", temp->dado);
        temp = temp->prox;
    }
    printf("\n");
}

int main() {
    int i,data;
    printf("Digite 5 numeros para fila\n");
    for (i = 0; i < 5; i++) {
        scanf("%d",&data);
        push_fila(&lista,data);
    }
    show_fila(lista);
    for (i = 0; i < 5; i++) {
        pop_fila(&lista);
        show_fila(lista);
    }
    return 0;
}

