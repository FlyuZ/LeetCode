class Solution {
public:
  int countArrangement(int N) {
    vector<int> cnt(N + 1);
    dfs(N, cnt);
    return cnt[0];
  }
  void dfs(int n, vector<int> &cnt) {
    if (n == 1) {
      cnt[0]++;
      return;
    }
    for (int i = 1; i < cnt.size(); i++) {
      if (cnt[i] == 0 && (n % i == 0 || i % n == 0)) {
        cnt[i] = n;
        dfs(n - 1, cnt);
        cnt[i] = 0;
      }
    }
  }
};
//打表
class Solution {
public:
    int countArrangement(int N_) {
        switch(N_) {
            case 1: return 1;
            case 2: return 2;
            case 3: return 3;
            case 4: return 8;
            case 5: return 10;
            case 6: return 36;
            case 7: return 41;
            case 8: return 132;
            case 9: return 250;
            case 10: return 700;
            case 11: return 750;
            case 12: return 4010;
            case 13: return 4237;
            case 14: return 10680;
            case 15: return 24679;
        }
    }
};
