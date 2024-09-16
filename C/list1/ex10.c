/*Joao Pedro Costa Guerios GRR20234965*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char text[100];
    file = fopen("arquivo.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    printf("Digite um texto para armazenar no arquivo: ");
    fgets(text, sizeof(text), stdin);
    fprintf(file, "%s", text);
    fclose(file);
    file = fopen("arquivo.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    printf("\nConteúdo do arquivo:\n");
    while (fgets(text, sizeof(text), file) != NULL) {
        printf("%s", text);
    }
    fclose(file);
    return 0;
}

