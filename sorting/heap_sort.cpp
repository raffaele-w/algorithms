void max_heapify(int* A, int n, int i) {
    while (i <= n / 2) {
        int largest = i;
        if (2 * i <= n && A[2 * i - 1] > A[i - 1]) largest = 2 * i;
        if (2 * i + 1 <= n && A[2 * i] > A[largest - 1]) largest = 2 * i + 1;
        if (largest == i) break;
        swap(A[i - 1], A[largest - 1]);
        i = largest;
    }
}

// T = O(n)
void build_max_heap(int* A, int n) {
    for (int i = n / 2; i > 0; i--) {
        max_heapify(A, n, i);
    }
}

// T = O(nlgn), S = O(1)
void heap_sort(int* A, int n) {
    build_max_heap(A, n);
    for (int i = n - 1; i > 0; i--) {
        swap(A[i], A[0]);
        max_heapify(A, i, 1);
    }
}

