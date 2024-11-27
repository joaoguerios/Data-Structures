#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int dado;
    struct node *esq;
    struct node *dir;
    struct node *pai;
} Node;

Node* criaAB(int dado) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->dado = dado;
    node->esq = NULL;
    node->dir = NULL;
    node->pai = NULL;
    return node;
}

void em_ordem(Node *raiz) {
    if (raiz == NULL) return;
    em_ordem(raiz->esq);
    printf("%d\n", raiz->dado);
    em_ordem(raiz->dir);
}

int insereFilhoEsquerda(Node *raiz, int dado) {
    if (raiz->esq == NULL) {
        Node *novoFilho = criaAB(dado);
        raiz->esq = novoFilho;
        novoFilho->pai = raiz;
        return 1;
    } else {
        return 0;
    }
}

int insereFilhoDireita(Node *raiz, int dado) {
    if (raiz->dir == NULL) {
        Node *novoFilho = criaAB(dado);
        raiz->dir = novoFilho;
        novoFilho->pai = raiz;
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Node *raiz = criaAB(10);
    insereFilhoEsquerda(raiz, 5);
    insereFilhoEsquerda(raiz, 6);
    insereFilhoEsquerda(raiz, 7);
    insereFilhoDireita(raiz, 15);
    printf("Árvore em ordem:\n");
    em_ordem(raiz);
    return 0;
}
