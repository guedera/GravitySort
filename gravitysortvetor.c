#include <stdio.h>

// Gravity Sort usando apenas vetor de alturas
void GravitySort(int v[], int n) {
    if (n <= 1) return;

    // acha o max (número de colunas necessárias)
    int max = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > max) max = v[i];
    }

    // vetor de alturas: heights[j] = quantas contas na coluna j
    int heights[max];
    
    // zera o vetor de alturas
    for (int j = 0; j < max; j++) {
        heights[j] = 0;
    }

    // preenche as alturas: para cada v[i], incrementa as primeiras v[i] colunas
    for (int i = 0; i < n; i++) {
        int q = v[i];
        if (q > max) q = max;
        for (int j = 0; j < q; j++) {
            heights[j]++;
        }
    }

    printf("Alturas iniciais: ");
    for (int j = 0; j < max; j++) {
        printf("%d ", heights[j]);
    }
    printf("\n");

    // simula a gravidade: redistribui as contas da esquerda para direita
    // processando da direita para esquerda para simular a queda
    for (int col = max - 1; col >= 0; col--) {
        // as contas desta coluna "caem" - queremos redistribuir
        // para simular o efeito de gravidade, reorganizamos as alturas
        
        // conta total de contas até esta coluna (inclusive)
        int total_beads = 0;
        for (int j = 0; j <= col; j++) {
            total_beads += heights[j];
        }
        
        // redistribui: as colunas da direita ficam com mais contas (fundo)
        // zera as alturas até esta coluna
        for (int j = 0; j <= col; j++) {
            heights[j] = 0;
        }
        
        // coloca as contas nas posições mais à direita (fundo)
        int remaining = total_beads;
        for (int j = col; j >= 0 && remaining > 0; j--) {
            int can_fit = n; // máximo que cabe numa coluna
            int to_place = (remaining <= can_fit) ? remaining : can_fit;
            heights[j] = to_place;
            remaining -= to_place;
        }

        printf("Após processar coluna %d: ", col);
        for (int j = 0; j < max; j++) {
            printf("%d ", heights[j]);
        }
        printf("\n");
    }

    // reconstrói o vetor ordenado a partir das alturas
    int idx = 0;
    for (int j = 0; j < max; j++) {
        for (int count = 0; count < heights[j]; count++) {
            if (idx < n) {
                v[idx++] = j + 1; // altura da coluna j representa números de valor j+1
            }
        }
    }
}

//-------------------------------------------------------------------//
int main() {
    int v[] = {4, 0, 11, 11, 11, 8, 2, 2, 5, 9, 14};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Vetor original: ");
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
