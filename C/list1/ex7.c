#include <stdio.h>
#define MAX_SIZE 5

typedef struct {
    int array[MAX_SIZE];
    int front;
    int rear;
} Fila;

void inicializa_fila(Fila *f) {
    f->front = -1;
    f->rear = -1;
}

void enqueue(Fila *f, int dado) {
    if (f->rear < MAX_SIZE - 1) {
        if (f->front == -1) {
            f->front = 0;
        }
        f->rear++;
        f->array[f->rear] = dado;
    } else {
        printf("A fila está cheia!\n");
    }
}

int dequeue(Fila *f) {
    if (f->front != -1) {
        int data = f->array[f->front];
        if (f->front == f->rear) {
            f->front = -1;
            f->rear = -1;
        } else {
            f->front++;
        }
        return data;
    } else {
        printf("A fila está vazia!\n");
        return -1;
    }
}

void show_fila(Fila *f) {
    int i;
    if (f->front == -1) {
        printf("A fila está vazia!\n");
        return;
    }
    printf("Elementos da fila: ");
    for (i = f->front; i <= f->rear; i++) {
        printf("%d ", f->array[i]);
    }
    printf("\n");
}

int main() {
    Fila fila;
    inicializa_fila(&fila);
    int i, data;
    printf("Etapa de inserção na fila:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &data);
        enqueue(&fila, data);
    }
    printf("Fila após inserção:\n");
    show_fila(&fila);
    for (i = 0; i < 5; i++) {
        dequeue(&fila);
        show_fila(&fila);
    }
    return 0;
}
