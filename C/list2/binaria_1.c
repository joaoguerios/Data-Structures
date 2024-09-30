/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>

int busca_binaria(int chave, int array[], int size) {
    int left = 0, right = size - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (array[mid] == chave) {
            return mid;
        } else if (array[mid] < chave) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main(void) {
    int array[] = {1, 3, 5, 7, 9}, chave = 1;
    int size = sizeof(array) / sizeof(array[0]);
    printf("%d\n", busca_binaria(chave, array, size));
    return 0;
}
