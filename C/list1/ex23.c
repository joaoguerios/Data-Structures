/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>
#include <time.h>

void bubbleSort(int arr[], int size) {
    int i,j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

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

void insertionSort(int arr[], int size) {
    int i,j;
    for (i = 1; i < size; i++) {
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
    int i,j;
    for ( i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[1000],i;
    for (i = 0; i < 1000; i++) {
        arr[i] = rand() % 1000;
    }

    int arr1[1000], arr2[1000], arr3[1000];
    for (i = 0; i < 1000; i++) {
        arr1[i] = arr2[i] = arr3[i] = arr[i];
    }

    clock_t start = clock();
    bubbleSort(arr1, 1000);
    clock_t end = clock();
    double time_taken_bubble = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do Bubble Sort: %f segundos\n", time_taken_bubble);

    start = clock();
    selectionSort(arr2, 1000);
    end = clock();
    double time_taken_selection = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do Selection Sort: %f segundos\n", time_taken_selection);

    start = clock();
    insertionSort(arr3, 1000);
    end = clock();
    double time_taken_insertion = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do Insertion Sort: %f segundos\n", time_taken_insertion);

    return 0;
}

