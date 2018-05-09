class Solution { //很有意思的题  可以出新生赛
  public int minSteps(int n) {
    int ans = 0;
    for (int i = 2; i <= n; i++) {
      while (n % i == 0) {
        ans += i;
        n /= i;
      }
    }
    return ans;
  }
}
