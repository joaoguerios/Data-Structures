/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>
#define MAX_SIZE 5

typedef struct {
    int array[MAX_SIZE];
    int top;
} Pilha;

void inicializa_pilha(Pilha *p) {
    p->top = -1;
}

void push_pilha(Pilha *p, int dado) {
    if (p->top < MAX_SIZE - 1) {
        p->top++;
        p->array[p->top] = dado;
    } else {
        printf("A pilha está cheia!\n");
    }
}

int pop_pilha(Pilha *p) {
    if (p->top >= 0) {
        int data = p->array[p->top];
        p->top--;
        return data;
    } else {
        printf("A pilha está vazia!\n");
        return -1;
    }
}

void show_pilha(Pilha *p) {
    int i;
    if (p->top == -1) {
        printf("A pilha está vazia!\n");
        return;
    }
    printf("Elementos da pilha: ");
    for ( i = 0; i <= p->top; i++) {
        printf("%d ", p->array[i]);
    }
    printf("\n");
}

int main() {
    Pilha pilha;
    inicializa_pilha(&pilha);
    int i,data;
    printf("etapa de push na pilha\n");
    for (i = 0; i < 5; i++) {
        scanf("%d",&data);
        push_pilha(&pilha, data);
    }
    printf("pilha apos push\n");
    show_pilha(&pilha);
    for (i = 0; i < 5; i++) {
        pop_pilha(&pilha);
        show_pilha(&pilha);
    }
    return 0;

    return 0;
}

