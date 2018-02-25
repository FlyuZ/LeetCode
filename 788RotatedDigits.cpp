class Solution {
public:
  int rotatedDigits(int N) {
    const int num[] = {0, 1, 2, 5, 6, 8, 9};
    int ans = 0;
    for (int i = 1; i < 7; i++) {
      if (i == 1 || i == 5)
        dfs(num[i], num, ans, false, N);
      else
        dfs(num[i], num, ans, true, N);
    }
    return ans;
  }
  void dfs(int cur, const int *num, int &ans, bool jud, int N) {
    if (cur > N)
      return;
    if (jud == true)
      ans++;
    for (int i = 0; i < 7; i++) {
      if (jud)
        dfs(cur * 10 + num[i], num, ans, true, N);
      else if (i == 0 || i == 1 || i == 5)
        dfs(cur * 10 + num[i], num, ans, false, N);
      else
        dfs(cur * 10 + num[i], num, ans, true, N);
    }
  }
};
