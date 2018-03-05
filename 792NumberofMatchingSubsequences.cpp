class Solution {
public:
  int numMatchingSubseq(string S, vector<string> &words) {
    int ans = 0;
    vector<vector<int>> record(26);
    for (int i = 0; i < S.size(); i++)
      record[S[i] - 'a'].push_back(i);
    for (auto word : words) {
      int index = -1;
      bool flag = true;
      for (int i = 0; i < word.size(); i++) {
        auto iter = upper_bound(record[word[i] - 'a'].begin(),
                                record[word[i] - 'a'].end(), index);
        if (iter == record[word[i] - 'a'].end()) {
          flag = false;
          break;
        }
        index = *iter;
      }
      if (flag)
        ans++;
    }
    return ans;
  }
};
