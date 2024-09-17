/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct CircularLinkedList {
    Node* head;
    int size;
} CircularLinkedList;

void initList(CircularLinkedList* list) {
    list->head = (Node*)malloc(sizeof(Node));
    list->head->next = list->head;
    list->size = 0;
}

void insert(CircularLinkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    Node* temp = list->head;
    while (temp->next != list->head) {
        temp = temp->next;
    }
    newNode->next = list->head;
    temp->next = newNode;
    list->size++;
}

void removeElement(CircularLinkedList* list, int value) {
    Node* temp = list->head->next;
    Node* prev = list->head;

    while (temp != list->head) {
        if (temp->data == value) {
            prev->next = temp->next;
            free(temp);
            list->size--;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void printList(CircularLinkedList* list) {
    Node* temp = list->head->next;
    while (temp != list->head) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    CircularLinkedList list;
    initList(&list);
    insert(&list, 10);
    insert(&list, 20);
    insert(&list, 30);
    printList(&list);
    removeElement(&list, 20);
    printList(&list);
    return 0;
}

