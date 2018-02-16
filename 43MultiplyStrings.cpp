class Solution {
public:
  string multiply(string num1, string num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0 || num1 == "0" || num2 == "0")
      return "0";
    vector<int> v(len1 + len2, 0);
    for (int i = 0; i < len1; i++) {
      int carry = 0; //进位
      int n1 = num1[len1 - i - 1] - '0';
      for (int j = 0; j < len2; j++) {
        int n2 = num2[len2 - j - 1] - '0';
        int sum = n1 * n2 + v[i + j] + carry;
        carry = sum / 10;
        v[i + j] = sum % 10;
      }
      if (carry > 0)
        v[i + len2] += carry;
    }
    int st = len1 + len2 - 1;
    while (v[st] == 0)
      st--;
    string res = "";
    for (int i = st; i >= 0; i--)
      res += (v[i] + '0');
    return res;
  }
};
