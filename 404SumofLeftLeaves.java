/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
  int sum = 0;
  public int sumOfLeftLeaves(TreeNode root) {
    sum(root, null);
    return sum;
  }
  private void sum(TreeNode cur, TreeNode parent) {
    if (cur == null)
      return;
    sum(cur.left, cur);
    if (parent != null && parent.left == cur && cur.left == null &&
        cur.right == null)
      sum += cur.val;
    sum(cur.right, cur);
  }
}
