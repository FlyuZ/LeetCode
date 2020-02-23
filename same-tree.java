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
    int flag = 1;

    public boolean isSameTree(TreeNode p, TreeNode q) {
        dfs(p, q);
        if (flag == 1)
            return true;
        else
            return false;
    }

    void dfs(TreeNode p, TreeNode q) {
        if (p == null || q == null) {
            if (p != q) {
                flag = 0;
                return;
            }
            return;
        }
        if (p.val != q.val) {
            flag = 0;
            return;
        }
        dfs(p.left, q.left);
        dfs(p.right, q.right);
    }
}