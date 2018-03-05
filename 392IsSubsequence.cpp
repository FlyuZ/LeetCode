class Solution {
public:
  bool isSubsequence(string s, string t) {
    vector<vector<int>> record(26);
    for (int i = 0; i < t.size(); i++)
      record[t[i] - 'a'].push_back(i);
    int index = -1;
    for (int i = 0; i < s.size(); i++) {
      auto iter = upper_bound(record[s[i] - 'a'].begin(),
                              record[s[i] - 'a'].end(), index);
      if (iter == record[s[i] - 'a'].end()) {
        return false;
      }
      index = *iter;
    }
    return true;
  }
};
