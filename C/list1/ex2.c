/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *elementos;
    int tamanho;
} ConjuntoInteiros;

ConjuntoInteiros criarConjunto(int tamanho) {
    ConjuntoInteiros conjunto;
    conjunto.elementos = (int *)malloc(tamanho * sizeof(int));
    conjunto.tamanho = tamanho;
    return conjunto;
}

void adicionarElemento(ConjuntoInteiros *conjunto, int elemento) {
    if(conjunto->tamanho<=10){
        conjunto->
    }
}

void removerElemento(ConjuntoInteiros *conjunto, int elemento) {
    // Implemente a lógica para remover o elemento do conjunto
}

int consultarElemento(ConjuntoInteiros conjunto, int elemento) {
    // Implemente a lógica para verificar se o elemento está no conjunto
    return 0;
}

int main() {
    ConjuntoInteiros meuConjunto = criarConjunto(10);
    adicionarElemento(&meuConjunto, 5);
    removerElemento(&meuConjunto, 3);
    int resultado = consultarElemento(meuConjunto, 5);
    printf("Resultado da consulta: %d\n", resultado);
    free(meuConjunto.elementos);
    return 0;
}

