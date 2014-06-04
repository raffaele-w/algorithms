// Merge sort
// T = O(nlogn), S = O(n)
void merge_sort(int* arr, int begin, int end) {
    if (begin >= end) return;
    int mid = (begin + end) / 2;
    merge_sort(arr, begin, mid);
    merge_sort(arr, mid + 1, end);
    int buf[end - begin + 1];
    for (int i = begin, j = mid + 1, k = 0; k < end - begin + 1; k++) {
        int a = i <= mid ? arr[i] : INT_MAX;
        int b = j <= end ? arr[j] : INT_MAX;
        if (a <= b) {
            buf[k] = a;
            i++;
        } else {
            buf[k] = b;
            j++;
        }
    }
    for (int k = 0; k < end - begin + 1; k++) {
        arr[begin + k] = buf[k];
    }
}

