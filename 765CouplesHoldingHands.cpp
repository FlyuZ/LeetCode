//贪心 从第一个座位开始依次找搭档
class Solution {
public:
  int minSwapsCouples(vector<int> &row) {
    int len = row.size();
    int ans = 0;
    int temp;
    for (int i = 0; i < len; i += 2) {
      for (int j = i + 2; j < len; j++) {
        if (row[i] % 2 == 0 && row[j] == row[i] + 1) {
          ans++;
          temp = row[i + 1];
          row[i + 1] = row[j];
          row[j] = temp;
          continue;
        } else if (row[i] % 2 != 0 && row[j] == row[i] - 1) {
          ans++;
          temp = row[i + 1];
          row[i + 1] = row[j];
          row[j] = temp;
          continue;
        }
      }
    }
    return ans;
  }
};
