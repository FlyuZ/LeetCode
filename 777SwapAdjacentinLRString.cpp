class Solution {
public:
  bool canTransform(string start, string end) {
    int R1 = 0, R2 = 0, L1 = 0, L2 = 0;
    for (int i = 0; i < start.size(); i++) {
      if (start[i] == 'R')
        R1++;
      if (end[i] == 'R') {
        R2++;
        if (R2 > R1)
          return false;
      }
      if (end[i] == 'L') {
        if (R2 < R1)
          return false;
      }
    }
    for (int i = start.size() - 1; i >= 0; i--) {
      if (start[i] == 'L')
        L1++;
      if (end[i] == 'L') {
        L2++;
        if (L2 > L1)
          return false;
      }
      if (end[i] == 'R') {
        if (L2 < L1)
          return false;
      }
    }
    if (R1 != R2 || L1 != L2)
      return false;
    return true;
  }
};
