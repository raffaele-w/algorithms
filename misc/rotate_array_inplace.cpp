// T = O(n), S = O(1)
void rotate_left(vector<int> &A, int d) {
    reverse(A.begin(), A.begin() + d);
    reverse(A.begin() + d, A.end());
    reverse(A.begin(), A.end());
}

