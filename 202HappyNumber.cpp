class Solution { //这种循环， 然后一个一次走一步 ，一个一次走两步的做法很经典
public:
  bool isHappy(int n) {
    int one = n, two = replace(n);
    while (one != two) {
      one = replace(one);
      two = replace(replace(two));
    }
    if (one == 1)
      return true;
    else
      return false;
  }
  int replace(int num) {
    int sum = 0;
    while (num != 0) {
      int temp = num % 10;
      sum += temp * temp;
      num /= 10;
    }
    return sum;
  }
};
