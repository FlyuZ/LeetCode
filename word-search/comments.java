class Solution {
    private boolean[][] flag;

    public boolean exist(char[][] board, String word) {
        flag = new boolean[board.length][board[0].length];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == word.charAt(0)) {
                    if (dfs(board, word, 0, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    private boolean dfs(char[][] board, String word, int pos, int row, int column) {
        if (pos >= word.length()) return true;
        if (row >= board.length || column >= board[0].length || row < 0 || column < 0) {
            return false;
        }
        if (flag[row][column] || board[row][column] != word.charAt(pos)) {
            return false;
        } else {
            flag[row][column] = true;
            pos++;
            if (dfs(board, word, pos, row + 1, column) ||
                    dfs(board, word, pos, row - 1, column) ||
                    dfs(board, word, pos, row, column + 1) ||
                    dfs(board, word, pos, row, column - 1)) {
                return true;
            }
            flag[row][column] = false;
            return false;
        }
    }
}