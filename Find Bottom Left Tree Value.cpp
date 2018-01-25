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
    int findBottomLeftValue(TreeNode* root)
    {
        int ans;
        queue<TreeNode *> qu;
        qu.push(root);
        while(!qu.empty())
        {
            TreeNode* temp = qu.front();
            if(temp->right)
                qu.push(temp->right);
            if(temp->left)
                qu.push(temp->left);
            if(qu.size() == 1)
                ans = temp->val;
            qu.pop();
        }
        return ans;
    }
};
