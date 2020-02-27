class Solution {
    public boolean search(int[] nums, int target) {
        for (Integer i : nums) {
            if (i == target)
                return true;
        }
        return false;
    }
}