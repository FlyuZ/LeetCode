class Solution { //模拟
public:
  string solveEquation(string equation) {
    int i = 0;
    int para = 0, xpara = 0, flag = 1;
    while (i < equation.size()) {
      int sign = 1, num = 0;
      if (equation[i] == '=') {
        flag = -1;
        i++;
      }
      if (equation[i] == '-') {
        sign = -1;
        i++;
      }
      if (equation[i] == '+') {
        sign = 1;
        i++;
      }
      if (isdigit(equation[i])) {
        while (i < equation.size() && isdigit(equation[i])) {
          num = num * 10 + equation[i] - '0';
          i++;
        }
        if (i < equation.size() && equation[i] == 'x') {
          xpara += flag * sign * num;
          i++;
        } else
          para += flag * sign * num;
      } else {
        xpara += flag * sign;
        i++;
      }
    }
    if (para == 0 && xpara == 0)
      return "Infinite solutions";
    else if (xpara == 0)
      return "No solution";
    else
      return "x=" + to_string(para / xpara * -1);
  }
};
