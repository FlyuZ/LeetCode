class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.length - 2; i++) {
            int l = i + 1, r = nums.length - 1;
            while (l < r) {
                int cur = nums[l] + nums[r] + nums[i];
                if (Math.abs(cur - target) < Math.abs(ans - target))
                    ans = cur;
                if (cur > target)
                    r--;
                else if (cur < target)
                    l++;
                else
                    return cur;
            }
        }
        return ans;
    }
}