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
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      long long int sum = 0;
      int len = q.size();
      for (int i = 0; i < len; i++) {
        TreeNode *t = q.front();
        q.pop();
        if (t->left)
          q.push(t->left);
        if (t->right)
          q.push(t->right);
        sum += t->val;
      }
      ans.push_back((double)sum / len);
    }
    return ans;
  }
};
