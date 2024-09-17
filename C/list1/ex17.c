/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void initStack(Stack* stack) {
    stack->top = NULL;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Heap overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    Node* temp = stack->top;
    int popped = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return popped;
}

int peek(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->top->data;
    }
    return -1;
}

int main() {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    printf("Top element is %d\n", peek(&stack));
    printf("Popped element is %d\n", pop(&stack));
    return 0;
}

