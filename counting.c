#include <discordia.h> 

void CountingSort(pix_t *A, int n) {
    long max_id = A[0].id;
    for (int i = 1; i < n; i++)
        if (A[i].id > max_id) max_id = A[i].id;

    int *count = calloc(max_id + 1, sizeof(int));
    pix_t *output = malloc(n * sizeof(pix_t));

    for (int i = 0; i < n; i++) count[A[i].id]++;
    for (int i = 1; i <= max_id; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) output[--count[A[i].id]] = A[i];

    for (int i = 0; i < n; i++) A[i] = output[i];

    free(count);
    free(output);
}