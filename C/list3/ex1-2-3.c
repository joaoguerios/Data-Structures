#include <stdio.h>
#include <string.h>

// Exercicio 4 - Verifica se o vetor está ordenado
void verificaOrdenado(int v[], int n) {
    int i, ordenado = 1;
    for (i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            ordenado = 0;
            break;
        }
    }
    if (ordenado) printf("ORDENADO\n");
    else printf("NAO ORDENADO\n");
}

// Exercicio 5 - Ordena o vetor de maneira decrescente
void ordenaDecrescente(int v[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (v[i] < v[j]) {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

// Exercicio 6 - Insere um número no vetor ordenado
void insereOrdenado(int v[], int *n, int num) {
    int i = *n - 1;
    while (i >= 0 && v[i] > num) {
        v[i + 1] = v[i];
        i--;
    }
    v[i + 1] = num;
    (*n)++;
}

// Exercicio 7 - Busca binária em um vetor ordenado
int busca(int v[], int n, int num) {
    int inicio = 0, fim = n - 1, meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (v[meio] == num) return meio;
        else if (v[meio] < num) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

// Exercicio 12 - Bubble sort para ordenar uma string
void bubbleSort(char str[]) {
    int n = strlen(str);
    int i, j;
    char temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

// Exercicio 13 - Selection sort para ordenar nomes pelo tamanho
void selectionSort(char nomes[][100], int n) {
    int i, j, min;
    char temp[100];
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (strlen(nomes[j]) < strlen(nomes[min])) min = j;
        }
        strcpy(temp, nomes[i]);
        strcpy(nomes[i], nomes[min]);
        strcpy(nomes[min], temp);
    }
}

// Exercicio 14 - Quicksort para ordenar string em ordem decrescente
void troca(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
int particiona(char str[], int baixo, int alto) {
    char pivo = str[alto];
    int i = (baixo - 1), j;
    for (j = baixo; j < alto; j++) {
        if (str[j] > pivo) {
            i++;
            troca(&str[i], &str[j]);
        }
    }
    troca(&str[i + 1], &str[alto]);
    return (i + 1);
}
void quickSort(char str[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particiona(str, baixo, alto);
        quickSort(str, baixo, pi - 1);
        quickSort(str, pi + 1, alto);
    }
}

int main() {
    printf("1-Defina formalmente o problema da ordenacao\n");
    printf("É comum encontrarmos informacoes que nao estao ordenadas, para isso usamos metodos e algoritimos para ordena-los, entretanto essa ordenacao pode ser custosa se o algoritimo nao for bem desenvolvido, isso pode gerar gasto de recursos computacionais desnecessarios, alto tempo de resposta do algoritimo,, ocasionando assim lentidao e falta de otimizacao");
    printf("\n\n");
    printf("2-Defina formalmente o problema de encontrar o menor valor de um vetor\n");
    printf("Para encontrarmos o menor valor geralmente faz-se necessario a busca e comparacao em todos os itens do vetor, isso para casos em que o vetor nao esta ordenado, isso pode honerar muito processamento e deixar o programa lento");
    printf("\n\n");
    printf("3-Forneca um exemplo de aplicacao real que envolva o problema de ordenacao e de encontrar o menor valor\n");
    printf("Um exemplo de ordenacao, em aplicacoes que possuem telas de listagem e opcoes para efetuar ordenacoes. Exemplo de encontrar o menor valor, em alguns modelos de aprendizado de maquina se faz necessario encontrar tanto o menor valor quanto o maior valor para efetuar calculos estatisticos e normalizacoes");
    printf("\n\n");
    // Exercicio 4 - Verificar vetor ordenado
    int v1[] = {1, 2, 3, 4, 5};
    verificaOrdenado(v1, 5);

    // Exercicio 5 - Ordenar vetor de maneira decrescente
    int v2[] = {1, 5, 2, 4, 3};
    ordenaDecrescente(v2, 5);
    for (int i = 0; i < 5; i++) printf("%d ", v2[i]);
    printf("\n");

    // Exercicio 6 - Inserir número em vetor ordenado
    int v3[6] = {1, 2, 3, 4, 5};
    int n = 5, num = 3;
    insereOrdenado(v3, &n, num);
    for (int i = 0; i < n; i++) printf("%d ", v3[i]);
    printf("\n");

    // Exercicio 7 - Busca em vetor ordenado
    int pos = busca(v3, n, 4);
    if (pos != -1) printf("Encontrado na posicao %d\n", pos);
    else printf("Nao encontrado\n");

    // Exercicio 12 - Ordenar string com bubble sort
    char str1[] = "algoritmo";
    bubbleSort(str1);
    printf("%s\n", str1);

    // Exercicio 13 - Ordenar nomes pelo tamanho usando selection sort
    char nomes[5][100] = {"Ana", "Gabriel", "Joao", "Beatriz", "Carlos"};
    selectionSort(nomes, 5);
    for (int i = 0; i < 5; i++) printf("%s\n", nomes[i]);

    // Exercicio 14 - Ordenar string com quicksort em ordem decrescente
    char str2[] = "algoritmo";
    quickSort(str2, 0, strlen(str2) - 1);
    printf("%s\n", str2);

    return 0;
}

