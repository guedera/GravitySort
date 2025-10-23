#include <stdio.h>

// Gravity Sort usando apenas um vetor de alturas
void GravitySort(int v[], int n) {
    
    int mudou = 1;
    
    while (mudou) {
        mudou = 0;
        for (int i = n-1; i > 0; i--) {
            if (v[i-1] > v[i]) {
                mudou = 1;

                int diferenca = v[i-1]-v[i];

                //gravidade
                v[i] += diferenca;
                v[i-1] -= diferenca;
            }
        }
    }
}

//-------------------------------------------------------------------//
int main() {
    int v[] = {4, 0, 11, 11, 11, 8, 2, 2, 5, 9, 14};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Vetor inicial: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n\n");

    GravitySort(v, n);

    printf("\nVetor ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}
