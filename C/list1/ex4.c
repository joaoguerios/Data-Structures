/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>
#include <stdlib.h>

typedef struct listItem {
    int value;
    struct listItem *next;
}listItem;

listItem *itemCreate(){
    listItem *p ;
    p = (listItem *)malloc(sizeof (listItem));
    p->next = NULL;
    if(!p){
        printf("nao foi possivel criar/alocar o novo item");
    }
    return p;
}

void insere_inicio(listItem *init,int data){
    listItem *newlistItem;
    newlistItem =itemCreate();
    newlistItem->value = data;
    newlistItem ->next = init->next;
    init->next = newlistItem;
}

void insere_final(listItem *init, int data) {
    listItem *newlistItem;
    newlistItem = itemCreate();
    newlistItem->value = data;
    newlistItem->next = NULL;
    listItem *current = init;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newlistItem;
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

void printlist(listItem *listPointer) {
    listPointer = listPointer->next;
    while (listPointer != NULL) {
        printf("%d\n", listPointer->value);
        listPointer = listPointer->next;
    }
}

int main(void){
    listItem *listInit;
    listInit = itemCreate();
    int data=0,i=0;
    printf("Feito por Joao Pedro Costa Guerios GRR20234965\n");
    printf("Principais funcionalidades\n");
    printf("1-insere_final = insere itens no final da lista\n");
    printf("2-acha_item = busca o item na lista e retorna sucesso ou nao\n");
    printf("3-exclui_item = exclui o item da lista e retorna sucesso ou nao\n");
    printf("4-insere_inicio = insere itens no inicio da lista\n");
    printf("5-printlist = mostra os itens da lista na ordem do primeiro nodo ate o ultimo\n");
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
    printf("insira um numero para ficar no comeco da lista => ");
    scanf("%d",&data);
    insere_inicio(listInit,data);
    printf("numeros da lista\n");
    printlist(listInit);
    return 0;
}

