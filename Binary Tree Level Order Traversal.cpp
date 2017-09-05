/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    void DFS(vector<vector<int> > &res, TreeNode* root, int level)
    {
        if (root == NULL)
            return;
        if (res.size() == level)
            res.push_back({});
        res[level].push_back(root->val);
        DFS(res, root->left, level+1);
        DFS(res, root->right, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int> > res;
        DFS(res, root, 0);
        return res;
    }
};
