class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    vector<int> cur;
    vector<vector<int>> ans;
    fun(candidates, target, cur, ans, 0);
    return ans;
  }
  void fun(vector<int> &candidates, int target, vector<int> &cur,
           vector<vector<int>> &ans, int beg) {
    if (target == 0) {
      ans.push_back(cur);
      return;
    }
    for (int i = beg; i != candidates.size() && target >= candidates[i]; i++) {
      cur.push_back(candidates[i]);
      fun(candidates, target - candidates[i], cur, ans, i);
      cur.pop_back();
    }
  }
};
