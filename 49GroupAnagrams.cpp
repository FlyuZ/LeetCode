class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    if (strs.empty())
      return {};
    vector<vector<string>> ans;
    map<string, vector<string>> mv;
    //sort(strs.begin(), strs.end());
    for (int i = 0; i < strs.size(); i++) {
      string str = strs[i];
      sort(str.begin(), str.end());
      mv[str].push_back(strs[i]);
    }
    for (map<string, vector<string>>::iterator iter = mv.begin();
         iter != mv.end(); iter++)
      ans.push_back(iter->second);
    return ans;
  }
};
