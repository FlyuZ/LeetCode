class Solution { //简单贪心
public:
  vector<int> partitionLabels(string S) {
    vector<int> ans;
    vector<int> pos(26, 0);
    for (int i = 0; i < S.size(); i++)
      pos[S[i] - 'a'] = i;
    int start = -1;
    int end = -1;
    for (int i = 0; i < S.size(); i++) {
      if (start == -1)
        start = i;
      end = std::max(end, pos[S[i] - 'a']);
      if (end == i) {
        ans.push_back(end - start + 1);
        start = -1;
      }
    }
    return ans;
  }
};
