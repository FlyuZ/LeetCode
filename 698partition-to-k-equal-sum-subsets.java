class Solution {//DFS入门题
  public boolean canPartitionKSubsets(int[] nums, int k) {
    Arrays.sort(nums);
    int sum = 0;
    for (int num : nums)
      sum += num;
    if (sum % k != 0)
      return false;
    int[] sums = new int[k];
    return dfs(nums, sums, sum / k, nums.length - 1);
  }
  public boolean dfs(int[] nums, int[] sums, int target, int curidx) {
    if (curidx == -1) {
      for (int i = 0; i < sums.length - 1; i++) {
        if (sums[i] != target)
          return false;
      }
      return true;
    }
    for (int i = 0; i < sums.length; i++) {
      if (sums[i] + nums[curidx] <= target) {
        sums[i] += nums[curidx];
        if (dfs(nums, sums, target, curidx - 1))
          return true;
        sums[i] -= nums[curidx];
      }
    }
    return false;
  }
}
