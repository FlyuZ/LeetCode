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
  vector<TreeNode *> generateTrees(int n) {
    if (n == 0)
      return {};
    return fun(1, n);
  }
  vector<TreeNode *> fun(int l, int r) {
    if (l > r) {
      return vector<TreeNode *>(1, NULL);
    }
    vector<TreeNode *> ans;
    for (int i = l; i <= r; i++) {
      vector<TreeNode *> lNode, rNode;
      lNode = fun(l, i - 1);
      rNode = fun(i + 1, r);
      for (int j = 0; j < lNode.size(); j++) {
        for (int k = 0; k < rNode.size(); k++) {
          TreeNode *tNode = new TreeNode(i);
          tNode->left = lNode[j];
          tNode->right = rNode[k];
          ans.push_back(tNode);
        }
      }
    }
    return ans;
  }
};
