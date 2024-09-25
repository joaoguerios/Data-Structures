#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *parent;
    int *rank;
    int n;
} UnionFind;


UnionFind* createUnionFind(int n) {
    int i;
    UnionFind* uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->parent = (int*)malloc(n * sizeof(int));
    uf->rank = (int*)malloc(n * sizeof(int));
    uf->n = n;
    for ( i = 0; i < n; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }
    return uf;
}


int find(UnionFind* uf, int x) {
    if (uf->parent[x] != x) {
        uf->parent[x] = find(uf, uf->parent[x]);
    }
    return uf->parent[x];
}


void unionSets(UnionFind* uf, int x, int y) {
    int rootX = find(uf, x);
    int rootY = find(uf, y);

    if (rootX != rootY) {
        if (uf->rank[rootX] > uf->rank[rootY]) {
            uf->parent[rootY] = rootX;
        } else if (uf->rank[rootX] < uf->rank[rootY]) {
            uf->parent[rootX] = rootY;
        } else {
            uf->parent[rootY] = rootX;
            uf->rank[rootX]++;
        }
    }
}

void freeUnionFind(UnionFind* uf) {
    free(uf->parent);
    free(uf->rank);
    free(uf);
}

int main() {
    int n = 6, m = 3,i,j;
    int estradas[3][2] = {{2, 3}, {3, 4}, {5, 6}};

    UnionFind* uf = createUnionFind(n);


    for ( i = 0; i < m; i++) {
        int a = estradas[i][0] - 1;
        int b = estradas[i][1] - 1;
        unionSets(uf, a, b);
    }


    int *componentes = (int*)malloc(n * sizeof(int));
    for ( i = 0; i < n; i++) {
        componentes[i] = find(uf, i);
    }

    int componentesDistintos = 0;
    int *representantes = (int*)malloc(n * sizeof(int));
    for ( i = 0; i < n; i++) {
        int isNewComponent = 1;
        for ( j = 0; j < componentesDistintos; j++) {
            if (componentes[i] == representantes[j]) {
                isNewComponent = 0;
                break;
            }
        }
        if (isNewComponent) {
            representantes[componentesDistintos++] = componentes[i];
        }
    }

    if (componentesDistintos == 1) {
        printf("Todas as vilas estao conectadas\n");
    } else {
        printf("Nao estao todas conectadas. Voce precisa de %d estradas adicionais.\n", componentesDistintos - 1);
        printf("Sugestão de estradas a serem construidas:\n");

        for ( i = 1; i < componentesDistintos; i++) {
            printf("Conecte a vila %d com a vila %d\n", representantes[0] + 1, representantes[i] + 1);
        }
    }

    free(componentes);
    free(representantes);
    freeUnionFind(uf);

    return 0;
}
