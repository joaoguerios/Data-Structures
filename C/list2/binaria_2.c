/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>
#include <string.h>

int busca_binaria(const char* chave, const char* array[], int size) {
    int left = 0, right = size - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (strcmp(array[mid],chave) == 0) {
            printf("%s - %s\n",array[mid],chave);
            return mid;
        } else if (strcmp(array[mid],chave) < 0 ) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main(void) {
    char* array[] = {"abacaxi", "banana", "laranja","maçã"};
    const char* chave = "maçã";
    int size = sizeof(array) / sizeof(array[0]);
    printf("%d\n", busca_binaria(chave, array, size));
    return 0;
}

