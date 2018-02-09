class Solution { // dp  匹配从i-j到j
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++) {
      for (int j = 1; j <= i; j++) {
        vector<string>::iterator res =
            find(wordDict.begin(), wordDict.end(), s.substr(i - j, j));
        if (res != wordDict.end()) {
          dp[i] = dp[i - j];
          if (dp[i])
            break;
        }
      }
    }
    return dp[s.size()];
  }
};
