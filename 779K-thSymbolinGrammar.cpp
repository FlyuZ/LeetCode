class Solution {
public:
  int kthGrammar(int N, int K) {
    int nums[] = {0, 1, 1, 0, 1, 0, 0, 1};
    int cnt = 0;
    while (N > 4) {
      int po = pow(2, N - 2);
      if (K > po) {
        K -= po;
        cnt++;
        N--;
      } else {
        N--;
      }
    }
    if (N <= 4) {
      if (cnt % 2 == 0)
        return nums[K - 1];
      else if (nums[K - 1] == 0)
        return 1;
      else
        return 0;
    }
  }
};
