class Solution {
    public int minPathSum(int[][] grid) {
        if (grid.length == 0)
            return 0;
        int m = grid.length, n = grid[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) {
                    grid[i][j] = grid[i][j] + ((j - 1 >= 0) ? grid[i][j - 1] : 0);
                } else if (j == 0) {
                    grid[i][j] = grid[i][j] + ((i - 1 >= 0) ? grid[i - 1][j] : 0);
                } else {
                    grid[i][j] = grid[i][j] + Math.min(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }
        return grid[m - 1][n - 1];
    }
}