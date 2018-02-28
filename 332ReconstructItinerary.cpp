class Solution {
public:
  unordered_map<string, priority_queue<string, vector<string>, greater<string>>>
      graph;
  vector<string> findItinerary(vector<pair<string, string>> tickets) {
    for (auto e : tickets)
      graph[e.first].push(e.second);
    vector<string> res;
    dfs("JFK", res);
    reverse(res.begin(), res.end());
    return res;
  }
  void dfs(string vt, vector<string> &res) {
    auto &edges = graph[vt];
    while (!edges.empty()) {
      string to_vt = edges.top();
      edges.pop();
      dfs(to_vt, res);
    }
    res.push_back(vt);
  }
};
