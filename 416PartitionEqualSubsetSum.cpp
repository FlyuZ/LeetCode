class Solution { // 经典DP  每样物品只有一个 是否能装满一个固定大小的容器
public:
  bool canPartition(vector<int> &nums) {
    int sum = 0;
    for (auto num : nums)
      sum += num;
    if (sum % 2 == 1 || nums.empty())
      return false;
    sum /= 2;
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for (auto num : nums) {
      for (int j = sum; j >= num; j--) {
        if (dp[j - num] == true)
          dp[j] = true;
      }
    }
    return dp[sum];
  }
};
