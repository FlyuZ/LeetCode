class Solution { //参考Lis的思想
public:
  int characterReplacement(string s, int k) {
    vector<int> cnt(26, 0);
    int i = 0;
    for (int j = 0; j < s.length(); j++) {
      cnt[s[j] - 'A']++;
      int len = j - i + 1;
      if ((len - *max_element(cnt.begin(), cnt.end())) > k) {
        cnt[s[i] - 'A']--;
        i++;
      }
    }
    return s.length() - i;
  }
};
