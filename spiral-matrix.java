class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        if (matrix.length == 0)
            return res;
        int m = matrix.length, n = matrix[0].length;
        int up = 0, down = m - 1, left = 0, right = n - 1;
        while (true) {
            for (int i = left; i <= right; i++)
                res.add(matrix[up][i]);
            if (up == down)
                break;
            up++;
            for (int i = up; i <= down; i++)
                res.add(matrix[i][right]);
            if (left == right)
                break;
            right--;
            for (int i = right; i >= left; i--)
                res.add(matrix[down][i]);
            if (up == down)
                break;
            down--;
            for (int i = down; i >= up; i--)
                res.add(matrix[i][left]);
            if (left == right)
                break;
            left++;
        }
        return res;
    }
}