/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *minhaLista,i;
    minhaLista = (int *)malloc(5 * sizeof(int));
    if (minhaLista == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }
    for (i = 0; i < 5; i++) {
        minhaLista[i] = (i + 1) * 10;
    }
    for (i = 0; i < 5; i++) {
        printf("Elemento %d: %d\n", i, minhaLista[i]);
    }
    free(minhaLista);
    return 0;
}
