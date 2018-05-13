class Solution {
  public int[][] flipAndInvertImage(int[][] A) {
    int len1 = A.length;
    int len2 = A[0].length;
    for (int i = 0; i < len1; i++) {
      for (int j = 0; j < len2 / 2; j++) {
        int t = A[i][j];
        A[i][j] = A[i][len2 - j - 1];
        A[i][len2 - j - 1] = t;
      }
    }
    for (int i = 0; i < len1; i++) {
      for (int j = 0; j < len2; j++) {
        if (A[i][j] == 0)
          A[i][j] = 1;
        else if (A[i][j] == 1)
          A[i][j] = 0;
      }
    }
    return A;
  }
}
