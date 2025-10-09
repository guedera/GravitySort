#include <stdio.h>

void gravitySort(int v[], int n) {
    if (n <= 1) return;

    //acha o max
    int max = v[0];
    for (int i = 1; i < n; i++)
        if (v[i] > max) {
            max = v[i];
        }

    int freq[max + 1];
    for (int i = 0; i <= max; i++) {
        freq[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        freq[v[i]]++;
    }

    // reconstrói em ordem crescente
    int k = 0;
    for (int val = 0; val <= max; val++) {
        for (int c = 0; c < freq[val]; c++) {
            v[k++] = val;
        }
    }
}

int main() {
    int v[] = {4, 8, 3, 2, 5, 9, 167, 2, 32, 14, 16, 22, 1};
    int n = 13;

    gravitySort(v, n);

    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}
