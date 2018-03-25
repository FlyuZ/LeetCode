class Solution { //简单但很巧妙的题
public:
  int maxChunksToSorted(vector<int> &arr) {
    int maxr = 0;
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++) {
      maxr = std::max(maxr, arr[i]);
      if (maxr == i)
        cnt++;
    }
    return cnt;
  }
};
