/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>

void insertionSort(int arr[], int size) {
    int i,j;
    for ( i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);
    printf("Sorted array: \n");
    printArray(arr, size);
    return 0;
}
