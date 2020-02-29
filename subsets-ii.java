class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        res.add(new ArrayList<>());
        if (nums.length == 0)
            return res;
        Arrays.sort(nums);
        List<Integer> tmp = new ArrayList<>();
        int r = 1, l = 0, len = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i != 0 && (nums[i] == nums[i - 1]))
                l = res.size() - len;
            else
                l = 0;
            r = res.size();
            len = r - l;
            for (int j = l; j < r; j++) {
                tmp = new ArrayList<>(res.get(j));
                tmp.add(nums[i]);
                res.add(tmp);
            }
        }
        return res;
    }
}