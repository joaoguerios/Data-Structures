/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>
#include <time.h>

int sequentialSearch(int arr[], int size, int target) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[100000],i;
    for (i = 0; i < 100000; i++) {
        arr[i] = i;
    }
    int size = 100000;
    int target = 99999;

    clock_t start = clock();
    sequentialSearch(arr, size, target);
    clock_t end = clock();
    double time_taken_seq = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução da busca sequencial: %f segundos\n", time_taken_seq);

    start = clock();
    binarySearch(arr, size, target);
    end = clock();
    double time_taken_bin = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução da busca binária: %f segundos\n", time_taken_bin);

    return 0;
}
