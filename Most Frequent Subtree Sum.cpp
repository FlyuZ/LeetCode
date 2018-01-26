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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        unordered_map<int, int> cnt;
        int maxnum = 0;
        postorder(root, cnt, maxnum);
        for(const auto& x : cnt){
          if(x.second == maxnum){
            ans.push_back(x.first);
          }
        }
        return ans;
    }
    int postorder(TreeNode* node, unordered_map<int, int> &cnt, int &maxnum){
       if (!node)
           return 0;
       int left = postorder(node->left, cnt, maxnum);
       int right = postorder(node->right, cnt, maxnum);
       int sum = left + right + node->val;
       cnt[sum]++;
       maxnum = max(maxnum, cnt[sum]);
       return sum;
    }
};
