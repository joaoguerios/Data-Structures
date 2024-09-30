/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>

int busca_binaria(float chave, float array[], int size) {
    int left = 0, right = size - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (array[mid] == chave) {
            printf("foi encontrada no indice %d",mid);
            return mid;
        } else if (array[mid] < chave) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Nao foi encontrada");
    return -1;
}

int main(void) {
    float array[] = {0.5, 1.5, 2.5, 3.5}, chave = 2.5;
    int size = sizeof(array) / sizeof(array[0]);
    busca_binaria(chave, array, size);
    return 0;
}


