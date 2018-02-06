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
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ans;
    PreOrderTree(ans, root);
    return ans;
  }
  void PreOrderTree(vector<int> &ans, TreeNode *root) {
    if (root != NULL) {
      ans.push_back(root->val);
      PreOrderTree(ans, root->left);
      PreOrderTree(ans, root->right);
    }
  }
};
