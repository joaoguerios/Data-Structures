/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>

void selectionSort(int arr[], int size) {
    int i,j;
    for (i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
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
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, size);
    printf("Sorted array: \n");
    printArray(arr, size);
    return 0;
}

