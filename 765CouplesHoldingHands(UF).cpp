class Solution {
public:
  int n, dit[100];
  int f[100];

  void initf(int n) {
    for (int i = 0; i < n; i += 2) {
      f[i] = i;
      f[i + 1] = i;
    }
  }

  int getf(int a) {
    if (f[a] != a)
      f[a] = getf(f[a]);
    return f[a];
  }

  void merge(int a, int b) {
    int fa = getf(a), fb = getf(b);
    if (fa != fb) {
      f[fa] = fb;
    }
  }
  int minSwapsCouples(vector<int> &row) {
    n = row.size();
    initf(n);
    for (int i = 0; i < n; i++) {
      if (i & 1) {
        merge(row[i], row[i - 1]);
      }
    }
    int ans = n / 2;
    for (int i = 0; i < n; i++) {
      if (getf(i) == i)
        ans--;
    }
    return ans;
  }
};
