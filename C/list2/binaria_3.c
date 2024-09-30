/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>

int busca_binaria(int chave, int array[], int size) {
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
    int array[] = {10, 20, 30, 40, 50}, chave = 25;
    int size = sizeof(array) / sizeof(array[0]);
    busca_binaria(chave, array, size);
    return 0;
}

