class Solution { //双指针
public:
  int maxArea(vector<int> &height) {
    long long int maxarea = 0;
    for (int i = 0; i < height.size() - 1; i++) {
      if (i > 1 && height[i] < height[i - 1])
        continue;
      for (int j = i + 1; j < height.size(); j++) {
        int minh = std::min(height[i], height[j]);
        long long area = minh * (j - i);
        if (area > maxarea)
          maxarea = area;
      }
    }
    return maxarea;
  }
};

class Solution {
public:
  int maxArea(vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;
    int max_area = 0;
    while (left < right) {
      if (height[left] < height[right]) {
        int new_area = ((right - left) * height[left]);
        if (new_area > max_area) {
          max_area = new_area;
        }
        left++;
      } else { // left >= right
        int new_area = ((right - left) * height[right]);
        if (new_area > max_area) {
          max_area = new_area;
        }
        right--;
      }
    }
    return max_area;
  }
};
