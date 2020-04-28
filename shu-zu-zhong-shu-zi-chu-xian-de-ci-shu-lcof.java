class Solution {
    public int[] singleNumbers(int[] nums) {
        int[] ans = new int[2];
        if (nums.length <= 2)
            return nums;
        int x = 0;
        for (int num : nums)
            x ^= num;
        int flag = x & (-x);
        for (int num : nums) {
            if ((num & flag) == 0)
                ans[0] ^= num;
            else
                ans[0] ^= num;
        }
        return ans;
    }
}