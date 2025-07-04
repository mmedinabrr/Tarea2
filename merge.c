#include <discordia.h>

void merge(pix_t *A, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    pix_t *L = malloc(n1 * sizeof(pix_t));
    pix_t *R = malloc(n2 * sizeof(pix_t));

    for (int i = 0; i < n1; i++) L[i] = A[l + i];
    for (int j = 0; j < n2; j++) R[j] = A[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].id <= R[j].id) A[k++] = L[i++];
        else A[k++] = R[j++];
    }

    while (i < n1) A[k++] = L[i++];
    while (j < n2) A[k++] = R[j++];

    free(L);
    free(R);
}

void MergeSort(pix_t *A, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        MergeSort(A, l, m);
        MergeSort(A, m + 1, r);
        merge(A, l, m, r);
    }
}