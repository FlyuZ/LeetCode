class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int sum = 0;
    for (auto num : nums)
      sum += num;
    int ans = nums.size() * (nums.size() + 1) / 2;
    return ans - sum;
  }
};
