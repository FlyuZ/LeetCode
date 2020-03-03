class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int len = m + n - 1;
        m--;
        n--;
        for (int i = len; i >= 0; i--) {
            if (n < 0) {
                A[i] = A[m--];
            } else if (m < 0) {
                A[i] = B[n--];
            } else if (A[m] > B[n]) {
                A[i] = A[m--];
            } else {
                A[i] = B[n--];
            }
        }
    }
}