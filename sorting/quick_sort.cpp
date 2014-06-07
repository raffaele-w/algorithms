void init_random() {
    srand(time(0));
}

int random(int m, int n) {
    return m + rand() % (n - m + 1);
}

// Average: T = O(nlgn)
// Worse case: T = O(n^2)
void quick_sort(int* A, int p, int r) {
    if (p >= r) return;
    int k = random(p, r);
    swap(A[k], A[r]);
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] <= A[r]) swap(A[++i], A[j]);
    }
    swap(A[++i], A[r]);
    quick_sort(A, p, i - 1);
    quick_sort(A, i + 1, r);
}
