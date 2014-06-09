// T = O(n), 0 <= A[i] < 1
void bucket_sort(double* A, int n) {
    vector<vector<double> > buckets(n);
    for (int i = 0; i < n; i++) {
        buckets[int(A[i] * n)].push_back(A[i]);
    }
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }
    for (int i = 0, j = 0; i < n; i++) {
        for (double f : buckets[i]) {
            A[j++] = f;
        }
    }
}

