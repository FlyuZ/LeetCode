class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty())
      return false;
    int x = matrix.size(), y = matrix[0].size();
    int l = 0, r = x * y - 1, mid;
    while (l <= r) {
      mid = l + ((r - l) >> 1); //向下取整
      if (target < matrix[mid / y][mid % y])
        r = mid - 1;
      else if (target > matrix[mid / y][mid % y])
        l = mid + 1;
      else
        return true;
    }
    return false;
  }
};
