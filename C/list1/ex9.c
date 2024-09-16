/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>
#include <stdlib.h>

int buscaSequencial(int arr[]) {
    int i,j,temp;
    for (i = 0; i < sizeof(arr); i++) {
        for(j = 0; j < sizeof(arr)-1; j++){
            if(arr[j]<arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return 0;
}

int main(void) {
    int arr[10], i;
    for (i = 0; i < 10; i++) {
        arr[i] = rand() % 11;
    }
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    buscaSequencial(arr);
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

