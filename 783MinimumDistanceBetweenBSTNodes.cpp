/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  int minDiffInBST(TreeNode *root) {
    priority_queue<int> ans;
    PreOrderTree(root, ans);
    int res = 0x3f3f3f;
    int tmp1 = 0x3f3f3f;
    int tmp2;
    while (!ans.empty()) {
      tmp2 = ans.top();
      ans.pop();
      res = std::min(res, tmp1 - tmp2);
      tmp1 = tmp2;
    }
    return res;
  }
  void PreOrderTree(TreeNode *root, priority_queue<int> &ans) {
    if (root != NULL) {
      ans.push(root->val);
      PreOrderTree(root->left, ans);
      PreOrderTree(root->right, ans);
    }
  }
};
// inorder版
class Solution {
public:
  int minDiffInBST(TreeNode *root) {
    int pre = -0x3f3f3f;
    int ans = 0x3f3f3f;
    inorder(root, pre, ans);
    return ans;
  }
  void inorder(TreeNode *root, int &pre, int &ans) {
    if (root == NULL)
      return;
    inorder(root->left, pre, ans);
    ans = std::min(ans, root->val - pre);
    pre = root->val;
    inorder(root->right, pre, ans);
  }
};
