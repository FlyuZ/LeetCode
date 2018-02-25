class Solution {
public:
  string customSortString(string S, string T) {
    vector<int> cnt(26, 0);
    for (auto c : T) {
      int i = c - 'a';
      cnt[i]++;
    }
    string ans = "";
    for (auto c : S) {
      int i = c - 'a';
      while (cnt[i] > 0) {
        ans += c;
        cnt[i]--;
      }
    }
    for (int i = 0; i < 26; i++) {
      while (cnt[i] > 0) {
        char c = 'a' + i;
        ans += c;
        cnt[i]--;
      }
    }
    return ans;
  }
};
