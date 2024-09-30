/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>
#include <string.h>

int busca_simples(const char* chave, const char* array[], int size) {
    int i;
    for (i= 0; i < size; i++) {
        if (strcmp(array[i], chave) == 0) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    char* array[] = {"maçã", "banana", "laranja"};
    const char* chave = "banana";
    int size = sizeof(array) / sizeof(array[0]),i;
    printf("%d",busca_simples(chave, array, size));
    return 0;
}
