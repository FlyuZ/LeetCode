class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    int n = accounts.size();
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
      parent[i] = i;
    unordered_map<string, int> hash;
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < accounts[i].size(); j++) {
        if (hash.count(accounts[i][j])) {
          int k = hash[accounts[i][j]];
          if (accounts[k][0] == accounts[i][0]) {
            int x = Find(k, parent);
            int y = Find(i, parent);
            if (x != y) {
              parent[x] = y;
            }
          }
        } else {
          hash[accounts[i][j]] = i;
        }
      }
    }

    map<int, set<string>> merged;
    for (int i = 0; i < n; i++) {
      int k = Find(i, parent);
      merged[k].insert(accounts[i].begin(), accounts[i].end());
    }
    vector<vector<string>> ans;
    for (auto i : merged) {
      ans.push_back(vector<string>(i.second.begin(), i.second.end()));
    }
    return ans;
  }
  int Find(int x, vector<int> &parent) {
    return parent[x] == x ? x : parent[x] = Find(parent[x], parent);
  }
};
