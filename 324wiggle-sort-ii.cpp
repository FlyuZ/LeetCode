class Solution {
public:
  void wiggleSort(vector<int> &nums) {
    vector<int> temp(nums);
    sort(temp.begin(), temp.end());
    int len = temp.size();
    int large = len / 2 + (len % 2 == 0 ? -1 : 0);
    int small = len - 1;
    for (int i = 0, j = 1; i < len; i += 2, j += 2) {
      if (j < len)
        nums[j] = temp[small--];
      nums[i] = temp[large--];
    }
    return;
  }
};
