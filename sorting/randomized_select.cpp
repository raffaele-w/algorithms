void init_random() {
    srand(time(NULL));
}

int random(int s, int t) {
    return s + rand() % (t - s + 1);
}

// Avg time: O(n), Worst case: O(n^2)
int randomized_select(int* A, int p, int r, int ith) {
    if (p == r) return A[p];
    else if (ith > r - p) return randomized_select(A, p, r, r - p);
    else if (ith < 0) return randomized_select(A, p, r, 0);
    
    int q = random(p, r);
    swap(A[q], A[r]);
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] <= A[r]) swap(A[++i], A[j]);
    }
    swap(A[++i], A[r]);
    if (ith == i - p) return A[i];
    else if (ith < i - p) return randomized_select(A, p, i - 1, ith);
    else return randomized_select(A, i + 1, r, ith - i - 1);
}

