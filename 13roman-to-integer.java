class Solution {
  public int romanToInt(String s) {
    int res = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
      if (i != 0 && (getValue(s.charAt(i)) > getValue(s.charAt(i - 1)))) {
        res = res + (getValue(s.charAt(i)) - getValue(s.charAt(i - 1)));
        i--;
      } else {
        res = res + getValue(s.charAt(i));
      }
    }
    return res;
  }
  private int getValue(char cur) {
    if (cur == 'I')
      return 1;
    if (cur == 'V')
      return 5;
    if (cur == 'X')
      return 10;
    if (cur == 'L')
      return 50;
    if (cur == 'C')
      return 100;
    if (cur == 'D')
      return 500;
    if (cur == 'M')
      return 1000;
    return 0;
  }
}
