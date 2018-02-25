class Solution {
public:
  int numTilings(int N) {
    int dp[1005];
    const int mod = 1e9 + 7;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;
    dp[4] = 11;
    for (int i = 4; i <= N; i++) {
      dp[i] = dp[i - 1] * 2 % mod + dp[i - 3]; //坑点
      dp[i] %= mod;
    }
    return dp[N] % mod;
  }
};
