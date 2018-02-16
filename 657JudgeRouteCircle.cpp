class Solution { //没啥意思
public:
  bool judgeCircle(string moves) {
    int r = 0, l = 0, u = 0, d = 0;
    for (auto c : moves) {
      if (c == 'R')
        r++;
      else if (c == 'L')
        l++;
      else if (c == 'U')
        u++;
      else if (c == 'D')
        d++;
    }
    if (r != l)
      return false;
    if (u != d)
      return false;
    return true;
  }
};
