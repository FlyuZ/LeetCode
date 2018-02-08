class Solution { //大模拟= =。
public:
  string addBinary(string a, string b) {
    string ans;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int flag = 0;
    while (i >= 0 || j >= 0) {
      if (i < 0) {
        if (flag == 0)
          ans = b[j] + ans;
        else if (b[j] == '0') {
          ans = "1" + ans;
          flag = 0;
        } else if (b[j] == '1') {
          ans = "0" + ans;
        }
        j--;
      } else if (j < 0) {
        if (flag == 0)
          ans = a[i] + ans;
        else if (a[i] == '0') {
          ans = "1" + ans;
          flag = 0;
        } else if (a[i] == '1') {
          ans = "0" + ans;
        }
        i--;
      } else {
        if (a[i] == '0' && b[j] == '0') {
          if (flag == 0)
            ans = "0" + ans;
          else if (flag == 1) {
            ans = "1" + ans;
            flag = 0;
          }
        } else if ((a[i] == '1' && b[j] == '0') ||
                   (a[i] == '0' && b[j] == '1')) {
          if (flag == 0)
            ans = "1" + ans;
          else if (flag == 1)
            ans = "0" + ans;
        } else if (a[i] == '1' && b[j] == '1') {
          if (flag == 0) {
            ans = "0" + ans;
            flag = 1;
          } else if (flag == 1) {
            ans = "1" + ans;
          }
        }
        i--;
        j--;
      }
    }
    if (flag == 1)
      ans = "1" + ans;
    return ans;
  }
};

class Solution { // very smart
public:
  string addBinary(string a, string b) {
    string s = "";
    int c = 0, i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || c == 1) {
      c += i >= 0 ? a[i--] - '0' : 0;
      c += j >= 0 ? b[j--] - '0' : 0;
      s = char(c % 2 + '0') + s;
      c /= 2;
    }
    return s;
  }
};
