/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>
#define MAX 10
typedef struct lista{
    int dados[MAX];
    int inic,fim;
}tipo_lista;

int add(tipo_lista *lista, int dado){
    if(lista->fim<=MAX){
        lista->dados[lista->fim] = dado;
        (lista->fim)++;
        return 1;
    }else{
        return -1;
    }
}

int remover(tipo_lista *lista, int indice){
    int i;
    if(lista->fim<=MAX && indice>0){
        for(i=indice;i<lista->fim;i++)
            lista->dados[i] = lista->dados[i+1];
        (lista->fim)--;
        return 1;
    }
    return 0;
}
void percorrer_lista(const tipo_lista *lista) {
    int i;
    printf("Elementos da lista:\n");
    for (i = 0; i < lista->fim; i++) {
        printf("%d ", lista->dados[i]);
    }
    printf("\n");
}

int main(void) {
    int i=0;
    tipo_lista minha_lista;
    minha_lista.inic = 0;
    minha_lista.fim = 0;

    for(i=0;i<MAX;i++){
        add(&minha_lista,i);
    }
    percorrer_lista(&minha_lista);
    remover(&minha_lista, 1);
    percorrer_lista(&minha_lista);
    return 0;
}

