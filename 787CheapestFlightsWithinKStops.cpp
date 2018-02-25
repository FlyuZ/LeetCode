class Solution { // bellman form
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int K) {
    vector<int> ans(n, 0x3f3f3f);
    ans[src] = 0;
    for (int i = 0; i <= K; i++) {
      vector<int> tmp(ans);
      for (auto f : flights) {
        tmp[f[1]] = std::min(tmp[f[1]], ans[f[0]] + f[2]);
      }
      ans = tmp;
    }
    return ans[dst] == 0x3f3f3f ? -1 : ans[dst];
  }
};

class Solution { // dj
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int K) {
    unordered_map<int, unordered_map<int, int>> mp;
    for (auto f : flights)
      mp[f[0]][f[1]] = f[2];
    unordered_map<int, int> cost = mp[src];
    for (int i = 0; i < K; i++) {
      auto tmp = cost;
      for (auto e : tmp) {
        auto next = mp[e.first];
        for (auto f : next) {
          if (cost.count(f.first)) {
            cost[f.first] = std::min(cost[f.first], e.second + f.second);
          } else {
            cost[f.first] = e.second + f.second;
          }
        }
      }
    }
    return cost.count(dst) ? cost[dst] : -1;
  }
};
