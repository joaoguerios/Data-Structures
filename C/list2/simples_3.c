/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>

int busca_simples(int chave, int array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (array[i] == chave) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int array[] = {-3, -1, 0, 1, 2}, chave = -1;
    int size = sizeof(array) / sizeof(array[0]);
    printf("%d\n", busca_simples(chave, array, size));
    return 0;
}

