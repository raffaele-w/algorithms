// T = O(d(n + k)), k = 10
void radix_sort(int* A, int n, int d) {
    int B[n];
    int C[10];
    for (int i = 0, base = 1; i < d; i++, base *= 10) {
        fill(C, C + 10, 0);
        for (int j = 0; j < n; j++) {
            C[A[j] / base % 10]++;
        }
        for (int j = 1; j < 10; j++) {
            C[j] += C[j - 1];
        }
        for (int j = n - 1; j >= 0; j--) {
            B[--C[A[j] / base % 10]] = A[j];
        }
        for (int j = 0; j < n; j++) {
            A[j] = B[j];
        }
    }
}

