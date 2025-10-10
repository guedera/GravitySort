#include <stdio.h>

// Gravity Sort (Bead Sort)
void GravitySort(int v[], int n) {
    if (n <= 1) return;

    // acha o max (número de "contas" por linha)
    int max = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > max) max = v[i];
    }

    // matriz de contas (beads): n linhas, max colunas
    // beads[i][j] = 1 se a linha i tem conta na coluna j
    int beads[n][max];

    // zera a matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < max; j++) {
            beads[i][j] = 0;
        }
    }

    // preenche as contas: v[i] contas à esquerda em cada linha i
    for (int i = 0; i < n; i++) {
        int q = v[i];
        if (q > max) q = max;
        for (int j = 0; j < q; j++) {
            beads[i][j] = 1;
        }
    }

    // "gravidade": para cada coluna, as contas caem para o fundo
    int temp[n]; // para calcular as somas por linha e atualizar v
    for (int col = 0; col < max; col++) {
        // conta quantas contas existem nesta coluna
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (beads[i][col] == 1) count++;
        }

        // zera a coluna
        for (int i = 0; i < n; i++) {
            beads[i][col] = 0;
        }

        // coloca as contas no "fundo" da coluna
        for (int i = n - count; i < n; i++) {
            beads[i][col] = 1;
        }

        // após assentar esta coluna, o vetor corrente é a soma por linha
        for (int i = 0; i < n; i++) {
            int s = 0;
            for (int j = 0; j < max; j++) s += beads[i][j];
            temp[i] = s;
        }
        for (int i = 0; i < n; i++) v[i] = temp[i];

        printf("Final da coluna %d: ", col);
        for (int i = 0; i < n; i++) {
            printf("%d ", v[i]);
        }
        printf("\n");
    }
}

//-------------------------------------------------------------------//
int main() {
    int v[] = {4, 0, 11, 11, 11, 8, 2, 2, 5, 9, 14};
    int n = sizeof(v) / sizeof(v[0]);

    GravitySort(v, n);

    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}
