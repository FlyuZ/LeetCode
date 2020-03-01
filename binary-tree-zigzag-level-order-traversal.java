/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        dfs(res, root, 0);
        return res;
    }

    void dfs(List<List<Integer>> res, TreeNode root, int level) {
        if (root == null)
            return;
        if (res.size() == level)
            res.add(new ArrayList<Integer>());
        if (level % 2 == 0) {
            res.get(level).add(root.val);
        } else {
            res.get(level).add(0, root.val);
        }
        dfs(res, root.left, level + 1);
        dfs(res, root.right, level + 1);
    }
}