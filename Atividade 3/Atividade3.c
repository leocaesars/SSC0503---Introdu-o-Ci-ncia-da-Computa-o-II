#include <stdio.h>
#include <stdlib.h>

int trocas, cmp;

void insertion(int a[], int n) {
    trocas = 0;
    cmp = 0;

    for (int i = 1; i < n; i++) {
        int x = a[i];
        int j = i - 1;

        trocas++;
        while (j >= 0) {
            cmp++;
            if (a[j] > x) {
                a[j + 1] = a[j];
                trocas++;
                j--;
            } else {
                break;
            }
        }
        a[j + 1] = x;

        trocas++;
    }
}

void merge(int a[], int c, int f, int b[]) {
    if (c >= f) return;

    int m = (c + f) / 2;

    merge(a, c, m, b);
    merge(a, m + 1, f, b);

    int i1 = c, i2 = m + 1, j = c;

    while (i1 <= m && i2 <= f) {
        cmp++;
        if (a[i1] <= a[i2]) {
            b[j++] = a[i1++];
            trocas++;
        } else {
            b[j++] = a[i2++];
            trocas++;
        }
    }

    while (i1 <= m) {
        b[j++] = a[i1++];
        trocas++;
    }

    while (i2 <= f) {
        b[j++] = a[i2++];
        trocas++;
    }

    for (int i = c; i <= f; i++) {
        a[i] = b[i];
        trocas++;
    }
}

int main() {
    int numVetores;

    scanf("%d", &numVetores);

    int **vetores = (int **)malloc(numVetores * sizeof(int *));
    int *tamanhos = (int *)malloc(numVetores * sizeof(int));

    for (int i = 0; i < numVetores; i++) {
        scanf("%d", &tamanhos[i]);
    }

    for (int i = 0; i < numVetores; i++) {
        vetores[i] = (int *)malloc(tamanhos[i] * sizeof(int));
        for (int j = 0; j < tamanhos[i]; j++) {
            scanf("%d", &vetores[i][j]);
        }
    }

    for (int i = 0; i < numVetores; i++) {
        int N = tamanhos[i];

        int *copia = (int *)malloc(N * sizeof(int));
        int *buffer = (int *)malloc(N * sizeof(int));

        for (int j = 0; j < N; j++) {
            copia[j] = vetores[i][j];
        }

        insertion(vetores[i], N);
        printf("I %d %d %d\n", N, trocas, cmp);

        trocas = 0;
        cmp = 0;

        merge(copia, 0, N - 1, buffer);
        printf("M %d %d %d\n", N, trocas, cmp);

    }

    return 0;
}
