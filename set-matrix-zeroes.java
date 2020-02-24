class Solution {
    public void setZeroes(int[][] matrix) {
        List<Integer> x = new ArrayList<>();
        List<Integer> y = new ArrayList<>();
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] == 0) {
                    x.add(i);
                    y.add(j);
                }
            }
        }
        for (Integer i : x) {
            for (int j = 0; j < matrix[0].length; j++) {
                matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < matrix.length; i++) {
            for (Integer j : y) {
                matrix[i][j] = 0;
            }
        }
    }
}