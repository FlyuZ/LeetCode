class Solution {  //n3
public:
  int triangleNumber(vector<int> &nums) {
    if (nums.size() < 3)
      return 0;
    sort(nums.begin(), nums.end());
    int cnt = 0;
    for (int i = 0; i < nums.size() - 2; i++) {
      for (int j = i + 1; j < nums.size() - 1; j++) {
        for (int k = j + 1; k < nums.size(); k++) {
          if (nums[i] + nums[j] > nums[k])
            cnt++;
          else
            break;
        }
      }
    }
    return cnt;
  }
};

class Solution { // n2
public:
  int triangleNumber(vector<int> &nums) {
    if (nums.size() < 3)
      return 0;
    sort(nums.begin(), nums.end());
    int cnt = 0;
    for (int i = nums.size() - 1; i > 1; i--) {
      int j = i - 1, k = 0;
      while (k < j) {
        if (nums[j] + nums[k] > nums[i]) {
          cnt += (j - k);
          j--;
        } else
          k++;
      }
    }
    return cnt;
  }
};
