/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>

void busca_simples(int chave, int array[], int size) {
    int i,primeira_ocor = -1,vezes = 0;
    for (i = 0; i < size; i++) {
        if (array[i] == chave) {
            if(primeira_ocor == -1){
                primeira_ocor = i;
            }
            vezes += 1;
        }
    }
    if(vezes==0){
        printf("nenhum encontrado");
        return;
    }
    printf("primeira vez: %d\ntotal de vezes: %d",primeira_ocor,vezes);
}

int main(void) {
    int array[] = {5, 2, 5, 1, 3}, chave = 5;
    int size = sizeof(array) / sizeof(array[0]);
    busca_simples(chave, array, size);
    return 0;
}

