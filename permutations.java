class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        int[] vis = new int[nums.length];
        dfs(nums, res, new ArrayList<Integer>(), vis);
        return res;
    }

    public void dfs(int[] nums, List<List<Integer>> res, ArrayList<Integer> tmp, int[] vis) {
        if (tmp.size() == nums.length) {
            res.add(new ArrayList<>(tmp));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (vis[i] == 1)
                continue;
            tmp.add(nums[i]);
            vis[i] = 1;
            dfs(nums, res, tmp, vis);
            vis[i] = 0;
            tmp.remove(tmp.size() - 1);
        }
    }
}