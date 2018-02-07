class Solution { //贪心
public:
  string removeDuplicateLetters(string s) {
    vector<int> cnt(26, 0);
    vector<bool> vis(26, false);
    string ans;
    for (auto c : s) {
      cnt[c - 'a']++;
    }
    for (auto c : s) {
      cnt[c - 'a']--;
      if (vis[c - 'a']) {
        continue;
      }
      while (!ans.empty() && c < ans.back() && cnt[ans.back() - 'a'] != 0) {
        vis[ans.back() - 'a'] = false;
        ans.pop_back();
      }
      ans.push_back(c);
      vis[c - 'a'] = true;
    }
    return ans;
  }
};
