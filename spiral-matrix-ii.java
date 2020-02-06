class Solution {
    public int[][] generateMatrix(int n) {
        if (n == 0)
            return null;
        int[][] matrix = new int[n][n];
        int up = 0, down = n - 1, left = 0, right = n - 1;
        int index = 1;
        while (true) {
            for (int i = left; i <= right; i++)
                matrix[up][i] = index++;
            if (up == down)
                break;
            up++;
            for (int i = up; i <= down; i++)
                matrix[i][right] = index++;
            if (left == right)
                break;
            right--;
            for (int i = right; i >= left; i--)
                matrix[down][i] = index++;
            if (up == down)
                break;
            down--;
            for (int i = down; i >= up; i--)
                matrix[i][left] = index++;
            if (left == right)
                break;
            left++;
        }
        return matrix;
    }
}