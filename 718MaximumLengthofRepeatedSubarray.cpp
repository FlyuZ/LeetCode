// subarray  子数组 指数组中连续的一段数组  与子序列不同
// dp  A数组前i 和B数组前j 的子问题
class Solution {
public:
  int findLength(vector<int> &A, vector<int> &B) {
    vector<vector<int>> dp(A.size(), vector<int>(B.size(), 0));
    int ans = 0;
    for (int i = 0; i < A.size(); i++) {
      for (int j = 0; j < B.size(); j++) {
        if (A[i] == B[j]) {
          if (i == 0 || j == 0)
            dp[i][j] = 1;
          else
            dp[i][j] = dp[i - 1][j - 1] + 1;
          ans = std::max(ans, dp[i][j]);
        }
      }
    }
    return ans;
  }
};
