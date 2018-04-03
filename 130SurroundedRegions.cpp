class Solution {
public:
  void solve(vector<vector<char>> &board) {
    if (board.size() < 1)
      return;
    int n = board.size();
    int m = board[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      if (board[i][0] == 'O')
        q.push(make_pair(i, 0));
      if (board[i][m - 1] == 'O')
        q.push(make_pair(i, m - 1));
    }
    for (int i = 0; i < m; i++) {
      if (board[0][i] == 'O')
        q.push(make_pair(0, i));
      if (board[n - 1][i] == 'O')
        q.push(make_pair(n - 1, i));
    }
    int tox[] = {1, 0, -1, 0};
    int toy[] = {0, 1, 0, -1};
    while (!q.empty()) {
      pair<int, int> t = q.front();
      q.pop();
      board[t.first][t.second] = 'N';
      for (int i = 0; i < 4; i++) {
        int x = t.first + tox[i];
        int y = t.second + toy[i];
        if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'O')
          q.push(make_pair(x, y));
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == 'N')
          board[i][j] = 'O';
        else
          board[i][j] = 'X';
      }
    }
  }
};
