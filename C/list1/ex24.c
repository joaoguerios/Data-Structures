/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>
#define SIZE 5

typedef struct {
    int items[SIZE];
    int front, rear;
} CircularQueue;

void initQueue(CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(CircularQueue* q) {
    return (q->front == 0 && q->rear == SIZE - 1) || (q->rear == (q->front - 1) % (SIZE - 1));
}

int isEmpty(CircularQueue* q) {
    return q->front == -1;
}

void enqueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = q->rear = 0;
    } else if (q->rear == SIZE - 1 && q->front != 0) {
        q->rear = 0;
    } else {
        q->rear++;
    }
    q->items[q->rear] = value;
}

int dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else if (q->front == SIZE - 1) {
        q->front = 0;
    } else {
        q->front++;
    }
    return data;
}
