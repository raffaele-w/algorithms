// T = O(n + k), stable sorting
void counting_sort(int* A, int n, int k) {
    int B[n];
    int C[k + 1];
    fill(C, C + k + 1, 0);
    for (int i = 0; i < n; i++) {
        C[A[i]]++;
    }
    for (int i = 1; i <= k + 1; i++) {
        C[i] += C[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        B[--C[A[i]]] = A[i];
    }
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
}

