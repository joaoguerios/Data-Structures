/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000
#define MAX 10000

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

void selectionSort(int arr[], int N) {
    int i,j;
    for ( i = 0; i < N - 1; i++) {
        int min_idx = i;
        for ( j = i + 1; j < N; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}


int main(void) {
    int array[SIZE], chave = 9998,i;
    int size = sizeof(array) / sizeof(array[0]);
    int generated[MAX + 1] = {0};
    int count = 0;

    srand(time(NULL));
    while (count < SIZE) {
        int num = (rand() % MAX) + 1;
        if (!generated[num]) {
            array[count] = num;
            generated[num] = 1;
            count++;
        }
    }
    selectionSort(array,size);
        for ( i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("%d\n", busca_binaria(chave, array, size));
    return 0;
}
