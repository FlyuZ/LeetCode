class Solution {
public:
  vector<string> letterCasePermutation(string S) {
    vector<string> ans;
    string s = "";
    dfs(S, ans, 0, S.size(), s);
    return ans;
  }
  void dfs(string S, vector<string> &ans, int cnt, int len, string cur) {
    if (cnt == len) {
      ans.push_back(cur);
      return;
    }
    if (S[cnt] <= '9' && S[cnt] >= '0') {
      char c = S[cnt];
      dfs(S, ans, cnt + 1, len, cur + c);
    } else if (S[cnt] <= 'z' && S[cnt] >= 'a') {
      char c = S[cnt];
      dfs(S, ans, cnt + 1, len, cur + c);
      c -= 32;
      dfs(S, ans, cnt + 1, len, cur + c);
    } else if (S[cnt] <= 'Z' && S[cnt] >= 'A') {
      char c = S[cnt];
      dfs(S, ans, cnt + 1, len, cur + c);
      c += 32;
      dfs(S, ans, cnt + 1, len, cur + c);
    }
  }
};
