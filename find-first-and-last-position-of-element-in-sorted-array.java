class Solution {
    public int[] searchRange(int[] nums, int target) {
        if(nums.length == 0)
            return new int[]{-1, -1};
        return twofind(nums, target, 0, nums.length - 1);
    }

    public int[] twofind(int[] nums, int target, int l, int r) {
        int mid = (l + r) / 2;
        while (l < r) {
            if (nums[l] == target && nums[r] == target)
                break;
            if (nums[mid] == target) {
                if (nums[l] < target)
                    l++;
                if (nums[r] > target)
                    r--;
            } else if (nums[mid] > target) {
                r--;
            } else if (nums[mid] < target) {
                l++;
            }
            mid = (l + r) / 2;
        }
        if (nums[l] == target && nums[r] == target)
            return new int[]{l, r};
        else
            return new int[]{-1, -1};
    }
}