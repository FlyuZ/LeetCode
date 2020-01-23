// 先倒叙查找nums[i] > nums[i - 1]的位置（i），然后把这之后的按从小到大排序，
// 然后把i-1 与其后第一个比它打大的数交换位置
class Solution {
    public void nextPermutation(int[] nums) {
        int len = nums.length;
        int flag = 0;
        for (int i = len - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                flag = 1;
                Arrays.sort(nums, i, len);
                for (int j = i; j < len; j++) {
                    if (nums[j] > nums[i - 1]) {
                        int temp = nums[j];
                        nums[j] = nums[i - 1];
                        nums[i - 1] = temp;
                        break;
                    }
                }
                break;
            }
        }
        if (flag == 0)
            Arrays.sort(nums);
    }
}