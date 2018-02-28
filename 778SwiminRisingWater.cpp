class Solution {
  // dijkstra 求从左上角到右下角所经过的边中权重最大值最小的一条路径
public:
  int swimInWater(vector<vector<int>> &grid) {
    int n = grid.size(), ans = std::max(grid[0][0], grid[n - 1][n - 1]);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    vis[0][0] = 1;
    int tox[] = {-1, 0, 1, 0};
    int toy[] = {0, -1, 0, 1};
    pq.push({ans, 0, 0});
    while (!pq.empty()) {
      auto cur = pq.top();
      pq.pop();
      ans = std::max(ans, cur[0]);
      for (int i = 0; i < 4; i++) {
        int r = cur[1] + tox[i];
        int c = cur[2] + toy[i];
        if (r >= 0 && r < n && c >= 0 && c < n && vis[r][c] == 0) {
          if (r == n - 1 && c == n - 1)
            return ans;
          pq.push({grid[r][c], r, c});
          vis[r][c] = 1;
        }
      }
    }
    return -1;
  }
};
