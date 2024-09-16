/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>

int buscaSequencial(int arr[], int num) {
    int i;
    for (i = 0; i < sizeof(arr); i++) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    int arr[10], i;
    for (i = 0; i < 10; i++) {
        arr[i] = i;
    }
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int indiceEncontrado = buscaSequencial(arr, 3);

    if (indiceEncontrado != -1) {
        printf("O elemento %d foi encontrado no índice %d.\n", 3, indiceEncontrado);
    } else {
        printf("O elemento %d não foi encontrado no array.\n", 3);
    }

    return 0;
}
