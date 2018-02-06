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
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ans;
    InOrderTree(ans, root);
    return ans;
  }
  void InOrderTree(vector<int> &ans, TreeNode *root) {
    if (root != NULL) {
      InOrderTree(ans, root->left);
      ans.push_back(root->val);
      InOrderTree(ans, root->right);
    }
  }
};
