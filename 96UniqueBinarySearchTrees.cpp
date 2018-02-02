//catalan
class Solution {
public:
  int numTrees(int n) {
    if (n == 0 || n == 1) {
      return 1;
    }
    long long int ans = 1;
    for (int i = n + 1; i <= n + n; i++) {
      ans *= i;
      ans /= i - n;
    }
    ans /= n + 1;
    return ans;
  }
};

class Solution {
public:
  int numTrees(int n) {
    vector<int> ans(n + 1);
    ans[0] = ans[1] = 1;
    for (int i = 2; i <= n; i++) {
      int sum = 0;
      for (int j = 0; j < i; j++) {
        sum += ans[j] * ans[i - j - 1];
      }
      ans[i] = sum;
    }
    return ans[n];
  }
};
