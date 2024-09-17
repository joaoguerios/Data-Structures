/*Joao Pedro Costa Guerios GRR20234965*/
typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

void insertFront(DNode** head, int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    *head = newNode;
}
