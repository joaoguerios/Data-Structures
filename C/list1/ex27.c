/*Joao Pedro Costa Guerios GRR20234965*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct CircularDoublyLinkedList {
    Node* head;
    int size;
} CircularDoublyLinkedList;

void initList(CircularDoublyLinkedList* list) {
    list->head = (Node*)malloc(sizeof(Node));
    list->head->next = list->head;
    list->head->prev = list->head;
    list->size = 0;
}

void insert(CircularDoublyLinkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    Node* tail = list->head->prev;
    newNode->next = list->head;
    newNode->prev = tail;
    tail->next = newNode;
    list->head->prev = newNode;
    list->size++;
}

void removeElement(CircularDoublyLinkedList* list, int value) {
    Node* temp = list->head->next;
    while (temp != list->head) {
        if (temp->data == value) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            list->size--;
            return;
        }
        temp = temp->next;
    }
}

void printList(CircularDoublyLinkedList* list) {
    Node* temp = list->head->next;
    while (temp != list->head) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    CircularDoublyLinkedList list;
    initList(&list);
    insert(&list, 10);
    insert(&list, 20);
    insert(&list, 30);
    printList(&list);
    removeElement(&list, 20);
    printList(&list);
    return 0;
}
