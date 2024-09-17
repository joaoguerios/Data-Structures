/*Joao Pedro Costa Guerios GRR20234965*/
typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

void insertEndCircularDoubly(DNode** head, int data) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    } else {
        DNode* last = (*head)->prev;

        last->next = newNode;
        newNode->prev = last;
        newNode->next = *head;
        (*head)->prev = newNode;
    }
}
