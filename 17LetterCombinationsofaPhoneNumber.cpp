class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return {};
    }
    string numToCh[10] = {"",    "",    "abc",  "def", "ghi",
                          "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    bfs(digits, ans, 0, "", numToCh);
    return ans;
  }

  void bfs(string digits, vector<string> &ans, int cnt, string cur,
           string numToCh[]) {
    if (digits.size() == cnt) {
      ans.push_back(cur);
    } else {
      int num = digits[cnt] - '0';
      for (int i = 0; i < numToCh[num].size(); i++) {
        bfs(digits, ans, cnt + 1, cur + numToCh[num][i], numToCh);
      }
    }
  }
};
