class Solution {   //floyd会超超时  改dfs
  public int[] sumOfDistancesInTree(int N, int[][] edges) {
    int[][] map = new int[N][N];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++)
        map[i][j] = 0x3f3f3f;
    }
    int len = edges.length;
    for (int i = 0; i < len; i++) {
      map[edges[i][0]][edges[i][1]] = 1;
      map[edges[i][1]][edges[i][0]] = 1;
    }
    for (int k = 0; k < N; k++) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          if (map[i][j] > map[i][k] + map[k][j])
            map[i][j] = map[i][k] + map[k][j];
        }
      }
    }
    int[] ans = new int[N];
    for (int i = 0; i < N; i++) {
      int t = 0;
      for (int j = 0; j < N; j++) {
        if (i != j)
          t += map[i][j];
      }
      ans[i] = t;
    }
    return ans;
  }
}
