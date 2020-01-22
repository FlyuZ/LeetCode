//将数组一分为二，其中一定有一个是有序的，另一个可能是有序，也能是部分有序。此时有序部分用二分法查找。
// 无序部分再一分为二，其中一个一定有序，另一个可能有序，可能无序。就这样循环.
//一分为2，判断开头的数值与中间数值大小，如果nums[0] < nums[mid]说明前半部分有序，否则后半部分有序
class Solution {
    public int search(int[] nums, int target) {
        return twofind(nums, target, 0, nums.length - 1);
    }

    public int twofind(int[] nums, int target, int l, int r) {
        if (l > r)
            return -1;
        int mid = (l + r) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[l] > nums[mid]) {
            if (target <= nums[r] && target > nums[mid])
                return twofind(nums, target, mid + 1, r);
            else
                return twofind(nums, target, l, mid - 1);
        } else {
            if (target >= nums[l] && target < nums[mid])
                return twofind(nums, target, l, mid - 1);
            else
                return twofind(nums, target, mid + 1, r);
        }
    }
}