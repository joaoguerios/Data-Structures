/*Joao Pedro Costa Guerios GRR20234965*/
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

void pushDynamic(StackNode** top, int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}
