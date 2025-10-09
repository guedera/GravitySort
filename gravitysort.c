/*
função gravitySort(vetor v, inteiro n)

    max = maior valor do vetor
    
    cria vetor de frequencias que tem tamanho (max + 1) com 0's
    
    para cada i em (0, 1, 2, ..., n-1)
        freq[v[i]] = freq[v[i]] + 1

    k = 0
    para cada j em (0, 1, 2, ..., max)
        para cada c em (0,1,2,...,freq[j]-1)
            v[k] = j
            k = k + 1
*/

#include <stdio.h>

//funcao sem criar uma matriz, dps fazer com matriz!
void gravitySort(int v[], int n) {
    //acha o max
    int max = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    
    //cria vetor de freqs
    int freq[max + 1];
    for (int i = 0; i <= max; i++) {
        freq[i] = 0;
    }

    //vetor de freqs com valores reais
    for (int i = 0; i < n; i++) {
        freq[v[i]]++;
    }
    printf("Lista de frequências: ");
    for (int i = 0; i < (max+1); i++) {
            printf("%d ", freq[i]);
        }
        printf("\n");

    //reconstrói o vetor em ordem cresc
    int k = 0;
    for (int val = 0; val <= max; val++) {
        for (int c = 0; c < freq[val]; c++) {
            v[k] = val;
            k++;
        }
        printf("Final do loop interno %d: ", val);
        for (int f = 0; f < n; f++) {
            printf("%d ", v[f]);
        }
        printf("\n");
    }
}

//-------------------------------------------------------------------//
int main() {
    int v[] = {4, 0, 11, 11, 11, 8, 2, 2, 5, 9, 14};
    int n = 11;

    gravitySort(v, n);

    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}
