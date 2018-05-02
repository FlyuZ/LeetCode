class Solution { // dp
public:
  int rob(vector<int> &nums) {
    int sz = nums.size();
    if (nums.empty())
      return 0;
    if (sz == 1)
      return nums[0];
    if (sz == 2)
      return std::max(nums[0], nums[1]);
    if (sz == 3) {
      int ans = std::max(nums[0], nums[1]);
      return std::max(ans, nums[2]);
    }
    if (sz == 4)
      return std::max(nums[0] + nums[2], nums[1] + nums[3]);
    vector<int> dp(sz + 1, 0);
    dp[0] = nums[0];
    dp[1] = nums[1];
    dp[2] = std::max(dp[0] + nums[2], dp[1]);
    for (int i = 3; i < sz - 1; i++) {
      dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 3] + nums[i]);
      dp[i] = std::max(dp[i], dp[i - 1]);
    }
    int ans = dp[sz - 2];
    dp[2] = nums[2];
    dp[3] = std::max(dp[1] + nums[3], dp[2]);
    for (int i = 4; i < sz; i++) {
      dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 3] + nums[i]);
      dp[i] = std::max(dp[i], dp[i - 1]);
    }
    ans = std::max(ans, dp[sz - 1]);
    return ans;
  }
};
