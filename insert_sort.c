void InsertSort(pix_t *A, int n) {
    int i, j;
    pix_t key;
    for (i = 1; i < n; i++) {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j].id > key.id) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}
