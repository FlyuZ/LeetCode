class Solution {
public:
  int longestPalindrome(string s) {
    int a[26] = {0};
    int b[26] = {0};
    for (auto c : s) {
      if (c > 96)
        a[c - 'a']++;
      else
        b[c - 'A']++;
    }
    int flag = 0;
    int ans = 0;
    for (int i = 0; i < 26; i++) {
      if (a[i] % 2 == 0)
        ans += a[i];
      else {
        if (a[i] > 2)
          ans += a[i] - 1;
        flag = 1;
      }
      if (b[i] % 2 == 0)
        ans += b[i];
      else {
        if (b[i] > 2)
          ans += b[i] - 1;
        flag = 1;
      }
    }
    if (flag)
      ans += 1;
    return ans;
  }
};
