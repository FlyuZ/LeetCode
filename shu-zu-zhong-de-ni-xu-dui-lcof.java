class Solution {
    public int reversePairs(int[] nums) {
        if (nums.length < 2)
            return 0;
        int[] temp = new int[nums.length];
        return reversePairs(nums, 0, nums.length - 1, temp);
    }

    public int reversePairs(int[] nums, int left, int right, int[] temp) {
        if (left == right)
            return 0;
        int mid = left + (right - left) / 2;
        int leftcount = reversePairs(nums, left, mid, temp);
        int rightcount = reversePairs(nums, mid + 1, right, temp);

        int crosscount = merge(nums, left, mid, right, temp);
        return leftcount + rightcount + crosscount;
    }

    public int merge(int[] nums, int left, int mid, int right, int[] temp) {
        for (int i = left; i <= right; i++) {
            temp[i] = nums[i];
        }
        int i = left;
        int j = mid + 1;
        int count = 0;
        for (int k = left; k <= right; k++) {
            if (i == mid + 1) {
                nums[k] = temp[j];
                j++;
            } else if (j == right + 1) {
                nums[k] = temp[i];
                i++;
            } else if (temp[i] <= temp[j]) {
                nums[k] = temp[i];
                i++;
            } else {
                nums[k] = temp[j];
                j++;
                count += (mid - i + 1);
            }
        }
        return count;
    }
}