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
  vector<int> rightSideView(TreeNode *root) {
    if (root == NULL)
      return {};
    vector<int> ans;
    queue<TreeNode *> q;
    q.push(root);
    int cnt = 1;
    int nextcnt = 0;
    int cur = 0;
    while (!q.empty()) {
      root = q.front();
      cur++;
      if (root->left) {
        q.push(root->left);
        nextcnt++;
      }
      if (root->right) {
        q.push(root->right);
        nextcnt++;
      }
      if (cur == cnt) {
        ans.push_back(root->val);
        cnt = nextcnt;
        nextcnt = 0;
        cur = 0;
      }
      q.pop();
    }
    return ans;
  }
};

//太巧妙了  (res.size() < level)  什么时候我能写出来这种代码
class Solution {
public:
  void recursion(TreeNode *root, int level, vector<int> &res) {
    if (root == NULL)
      return;
    if (res.size() < level)
      res.push_back(root->val);
    recursion(root->right, level + 1, res);
    recursion(root->left, level + 1, res);
  }

  vector<int> rightSideView(TreeNode *root) {
    vector<int> res;
    recursion(root, 1, res);
    return res;
  }
};
