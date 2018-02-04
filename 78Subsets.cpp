class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    if (nums.empty())
      return {};
    vector<vector<int>> ans;
    vector<int> cur;
    dfs(ans, nums, cur, 0);
    return ans;
  }
  void dfs(vector<vector<int>> &ans, vector<int> nums, vector<int> cur,
           int cnt) {
    ans.push_back(cur);
    if (cnt >= nums.size())
      return;
    for (int i = cnt; i < nums.size(); i++) {
      cur.push_back(nums[i]);
      dfs(ans, nums, cur, i + 1);
      cur.pop_back();
    }
  }
};
