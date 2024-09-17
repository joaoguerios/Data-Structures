/*Joao Pedro Costa Guerios GRR20234965*/
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct HeaderNode {
    int size;
    Node* next;
} HeaderNode;

HeaderNode* createList() {
    HeaderNode* header = (HeaderNode*)malloc(sizeof(HeaderNode));
    header->size = 0;
    header->next = NULL;
    return header;
}

void insertWithHeader(HeaderNode* header, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = header->next;
    header->next = newNode;

    header->size++;
}
