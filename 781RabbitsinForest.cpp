class Solution {
public:
  int numRabbits(vector<int> &answers) {
    if (answers.empty())
      return 0;
    vector<int> ans(1000, 0);
    int res = 0;
    for (int i = 0; i < answers.size(); i++) {
      ans[answers[i]]++;
    }
    res += ans[0];
    for (int i = 1; i <= 999; i++) {
      if (ans[i] == 0)
        continue;
      if (ans[i] % (i + 1) == 0) {
        res += (i + 1) * ans[i] / (i + 1);
      } else {
        res += (i + 1) * (ans[i] / (i + 1) + 1);
      }
    }
    return res;
  }
};
//简化版本
class Solution {
public:
  int numRabbits(vector<int> &answers) {
    unordered_map<int, double> m;
    for (int i = 0; i < answers.size(); i++)
      m[a[i] + 1]++;
    int res = 0;
    for (auto e : m)
      res += ceil(e.second / e.first) * e.first; //向上取整
    return res;
  }
};
