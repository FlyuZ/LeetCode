class Solution {//O2n普通做法
public:
  void sortColors(vector<int> &nums) {
    int zero = 0, one = 0, two = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        zero++;
      } else if (nums[i] == 1) {
        one++;
      } else if (nums[i] == 2) {
        two++;
      }
    }
    for (int i = 0; i < zero; i++) {
      nums[i] = 0;
    }
    for (int i = zero; i < zero + one; i++) {
      nums[i] = 1;
    }
    for (int i = zero + one; i < nums.size(); i++) {
      nums[i] = 2;
    }
  }
};
//更好的用快排
