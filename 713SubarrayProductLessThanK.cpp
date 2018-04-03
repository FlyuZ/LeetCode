class Solution {
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int ans = 0;
    int last, cur, j;
    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && nums[i] == nums[i - 1] && last > 0) {
        cur /= nums[i];
        last -= 1;
      } else {
        last = 0;
        cur = nums[i];
        j = i;
      }
      while (cur < k && j < nums.size()) {
        j++;
        cur *= nums[j];
        last++;
      }
      ans += last;
    }
    return ans;
  }
};
