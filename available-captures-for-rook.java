class Solution {
    public int numRookCaptures(char[][] board) {
        int x = 0, y = 0, cnt = 0;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == 'R') {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        for (int i = x; i < board[0].length; i++) {
            if (board[i][y] == 'B')
                break;
            if (board[i][y] == 'p') {
                cnt++;
                break;
            }
        }
        for (int i = x; i >= 0; i--) {
            if (board[i][y] == 'B')
                break;
            if (board[i][y] == 'p') {
                cnt++;
                break;
            }
        }
        for (int j = y; j < board.length; j++) {
            if (board[x][j] == 'B')
                break;
            if (board[x][j] == 'p') {
                cnt++;
                break;
            }
        }
        for (int j = y; j >= 0; j--) {
            if (board[x][j] == 'B')
                break;
            if (board[x][j] == 'p') {
                cnt++;
                break;
            }
        }
        return cnt;
    }
}