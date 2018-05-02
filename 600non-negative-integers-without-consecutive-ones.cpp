class Solution { // dp
public:
  int findIntegers(int num) {
    int dp[32];
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < 32; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    int ans = 0;
    int k = 31;
    int preInt = 0;
    while (k >= 0) {
      if (num & (1 << k)) {
        ans += dp[k];
        if (preInt)
          return ans;
        preInt = 1;
      } else
        preInt = 0;
      k--;
    }
    return ans + 1;
  }
};
