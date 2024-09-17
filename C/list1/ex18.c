/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* queue) {
    queue->front = queue->rear = NULL;
}

int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    Node* temp = queue->front;
    int value = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return value;
}

int main() {
    Queue queue;
    initQueue(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    printf("Dequeued element is %d\n", dequeue(&queue));
    return 0;
}

