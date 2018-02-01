class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    dfs(ans, "(", 1, 0, n);
    return ans;
  }
  void dfs(vector<string> &ans, string cur, int l, int r, int n) {
    if (l + r == n * 2) {
      ans.push_back(cur);
      return;
    }
    if (l == r) {
      dfs(ans, cur + "(", l + 1, r, n);
    } else if (l > r) {
      if (l == n) {
        dfs(ans, cur + ")", l, r + 1, n);
      } else if (l < n) {
        dfs(ans, cur + "(", l + 1, r, n);
        dfs(ans, cur + ")", l, r + 1, n);
      }
    }
  }
};
