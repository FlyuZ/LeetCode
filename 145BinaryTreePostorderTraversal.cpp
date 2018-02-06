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
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ans;
    PostOrderTree(ans, root);
    return ans;
  }
  void PostOrderTree(vector<int> &ans, TreeNode *root) {
    if (root != NULL) {
      PostOrderTree(ans, root->left);
      PostOrderTree(ans, root->right);
      ans.push_back(root->val);
    }
  }
};
