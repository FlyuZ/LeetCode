/**515
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
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL){
          return {};
        }
        queue<TreeNode*> qu;
        qu.push(root);
        vector<int> output;
        vector<int> cnt;
        cnt.push_back(1);
        cnt.push_back(0);
        int current = 0;
        int depth = 0;
        int ans = -2147483648;
        TreeNode* temp;
        while(!qu.empty()){
          temp = qu.front();
          if(ans < temp->val){
            ans = temp->val;
          }
          if(temp->left != NULL){
            cnt[depth+1]++;
            qu.push(temp->left);
          }
          if(temp->right != NULL){
            cnt[depth+1]++;
            qu.push(temp->right);
          }
          qu.pop();
          current++;
          if(current == cnt[depth]){
            output.push_back(ans);
            current = 0;
            cnt.push_back(0);
            depth = depth + 1;
            ans = -2147483648;
          }
        }
        return output;
    }
};

class Solution {
    vector<int> output;
public:
    void dfs(TreeNode* node, int depth) {
        if (node == NULL) {
            return;
        }
        if (output.size() < depth + 1) {
            output.push_back(node->val);
        }
        else {
            if (outputn[depth] < node->val) {
                output[depth] = node->val;
            }
        }
        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }
    vector<int> findValueMostElement(TreeNode* root) {
        if(root == NULL) {
            return output;
        }
        dfs(root, 0);
        return output;
    }
};
