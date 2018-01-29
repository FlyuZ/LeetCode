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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
          return 0;
        }
        int ans = 0;
        queue<pair<TreeNode*, int> > qu;
        qu.push(pair<TreeNode*, int>(root, 1));
        while(!qu.empty()){
          int l = qu.front().second;
          int len = qu.size();
          for(int i=0; i<len ;i++){
            TreeNode* temp = qu.front().first;
            int r = qu.front().second;
            qu.pop();
            if(temp->left){
              qu.push(pair<TreeNode*, int>(temp->left, r * 2));
            }
            if(temp->right){
              qu.push(pair<TreeNode*, int>(temp->right, r * 2 + 1));
            }
            ans = std::max(ans, r-l+1);
          }
        }
        return ans;
    }
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> lefts;
        int maxwidth = 0;
        dfs(root, 1, 0, lefts, maxwidth);
        return maxwidth;
    }
private:
    void dfs(TreeNode* node, int id, int depth, vector<int>& lefts, int& maxwidth) {
        if (node == NULL)
          return;
        if (depth >= lefts.size())
          lefts.push_back(id);
        maxwidth = std::max(maxwidth, id - lefts[depth] + 1);
        dfs(node->left, id * 2, depth + 1, lefts, maxwidth);
        dfs(node->right, id * 2 + 1, depth + 1, lefts, maxwidth);
    }
};
