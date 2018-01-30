class Solution { // floyd
public:
  int networkDelayTime(vector<vector<int>> &times, int N, int K) {
    int maxD = 0x3f3f3f;
    vector<vector<int>> edge(N, vector<int>(N, maxD));
    for (auto time : times) {
      edge[time[0] - 1][time[1] - 1] = time[2];
    }
    for (int i = 0; i < N; i++) {
      edge[i][i] = 0;
    }
    for (int k = 0; k < N; k++) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          edge[i][j] = std::min(edge[i][j], edge[i][k] + edge[k][j]);
        }
      }
    }
    int ans = -1;
    for (int i = 0; i < N; i++) {
      if (edge[K - 1][i] >= maxD) {
        return -1;
      }
      ans = std::max(ans, edge[K - 1][i]);
    }
    return ans;
  }
};

class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int N, int K) {
    int maxD = 0x3f3f3f;
    vector<int> dist(N + 1, maxD);
    dist[K] = 0;
    for (int i = 0; i < N; i++) {
      for (auto time : times) {
        int u = time[0], v = time[1], w = time[2];
        if (dist[u] != maxD && dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
        }
      }
    }
    int ans = *max_element(dist.begin()+1, dist.end());
    if (ans == maxD) {
      return -1;
    } else {
      return ans;
    }
  }
};
