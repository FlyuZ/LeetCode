class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        Set<List<Integer>> res = new HashSet<>();
        int[] vis = new int[nums.length];
        dfs(nums, res, new ArrayList<Integer>(), vis);
        List<List<Integer>> ans = new ArrayList<>(res);
        return ans;
    }

    public void dfs(int[] nums, Set<List<Integer>> res, ArrayList<Integer> tmp, int[] vis) {
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

//public class Solution {
//    public List<List<Integer>> permuteUnique(int[] nums) {
//        int len = nums.length;
//        List<List<Integer>> res = new ArrayList<>();
//        if (len == 0) {
//            return res;
//        }
//        // 修改 1：排序（这里用升序），为了剪枝方便
//        Arrays.sort(nums);
//        boolean[] used = new boolean[len];
//        // 使用 Deque 是 Java 官方 Stack 类的建议
//        Deque<Integer> path = new ArrayDeque<>(len);
//        dfs(nums, len, 0, used, path, res);
//        return res;
//    }
//
//    private void dfs(int[] nums, int len, int depth, boolean[] used, Deque<Integer> stack, List<List<Integer>> res) {
//        if (depth == len) {
//            res.add(new ArrayList<>(stack));
//            return;
//        }
//        for (int i = 0; i < len; i++) {
//            if (!used[i]) {
//                // 修改 2：在 used[i - 1] 刚刚被撤销的时候剪枝，说明接下来会被选择，搜索一定会重复，故"剪枝"
//                if (i > 0 && nums[i - 1] == nums[i] && !used[i - 1]) {
//                    continue;
//                }
//                used[i] = true;
//                stack.addLast(nums[i]);
//                dfs(nums, len, depth + 1, used, stack, res);
//                // 回溯，撤销选择
//                stack.removeLast();
//                used[i] = false;
//            }
//        }
//    }
//}