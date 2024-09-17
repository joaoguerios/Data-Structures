/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>
#include <stdlib.h>

typedef struct listItem {
    int value;
    struct listItem *next;
    struct listItem *prev;
} listItem;

listItem *itemCreate() {
    listItem *p = (listItem *)malloc(sizeof(listItem));
    p->next = p;
    p->prev = p;
    return p;
}

void insere_final(listItem *init, int data) {
    listItem *newItem = itemCreate();
    newItem->value = data;
    newItem->next = init;
    newItem->prev = init->prev;
    init->prev->next = newItem;
    init->prev = newItem;
}

listItem* exclui_item(listItem *listPointer, int data) {
    listItem *anterior = NULL;
    listItem *atual = listPointer;
    while (atual != NULL) {
        if (atual->value == data) {
            if (anterior == NULL) {
                listPointer = atual->next;
            } else {
                anterior->next = atual->next;
        }
        free(atual);
        printf("Item %d removido!\n", data);
        return listPointer;
        }
        anterior = atual;
        atual = atual->next;
    }
    printf("Item %d não encontrado na lista.\n", data);
    return NULL;
}

int acha_item(listItem *listPointer,int data){
    int posicao=0;
    while(listPointer!=NULL){
        if(listPointer->value==data){
            printf("achei o numero %d no nodo %d \n",data,posicao);
            return posicao;
        }
        posicao++;
        listPointer = listPointer->next;
    }
    printf("numero %d, nao foi encontrado \n",data);
    return 0;
}

void printlist(listItem *init) {
    listItem *current = init->next;
    while (current != init) {
        printf("%d\n", current->value);
        current = current->next;
    }
}


int main(void){
    listItem *listInit;
    listInit = itemCreate();
    int data=0,i=0;
    for(i=0;i<5;i++){
        printf("insira um numero para ficar no final da lista => ");
        scanf("%d",&data);
        insere_final(listInit,data);
    }
    printf("numeros da lista\n");
    printlist(listInit);
    printf("procurando um numero nao existente na lista => ");
    scanf("%d",&data);
    acha_item(listInit,data);
    printf("procurando um numero existente na lista => ");
    scanf("%d",&data);
    acha_item(listInit,data);
    printf("excluindo um numero que nao existe na lista => ");
    scanf("%d",&data);
    exclui_item(listInit,data);
    printf("excluindo um numero que existe na lista => ");
    scanf("%d",&data);
    exclui_item(listInit,data);
    printf("numeros da lista\n");
    printlist(listInit);
    return 0;
}
