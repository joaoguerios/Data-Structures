/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo_Pilha{
    int dado;
    struct Nodo_Pilha *prox;
}*NODOPTR;
NODOPTR pilha=NULL;
NODOPTR Cria_Nodo_Pilha(){
    NODOPTR p;
    p = (NODOPTR) malloc(sizeof(struct Nodo_Pilha));
    return p;
}
void push_pilha(int dado) {
    NODOPTR nodo;
    nodo = Cria_Nodo_Pilha();
    nodo->dado = dado;
    nodo->prox = pilha;
    pilha = nodo;
}
int pop_pilha() {
    NODOPTR nodo;
    int data;
    if (!pilha) {
        printf("A pilha esta vazia!!!");
        return -1;
    }
    nodo = pilha;
    data = nodo->dado;
    pilha = nodo->prox;
    free(nodo);
    return data;
}
void show_pilha(NODOPTR pilha) {
    if (!pilha) {
        printf("A pilha esta vazia!\n");
        return;
    }
    NODOPTR temp = pilha;
    while (temp != NULL) {
        printf("%d ", temp->dado);
        temp = temp->prox;
    }
    printf("\n");
}

int main() {
    int i,data;
    printf("etapa de push na pilha\n");
    for (i = 0; i < 5; i++) {
        scanf("%d",&data);
        push_pilha(data);
    }
    printf("pilha apos push\n");
    show_pilha(pilha);
    for (i = 0; i < 5; i++) {
        pop_pilha();
        show_pilha(pilha);
    }
    return 0;
}

