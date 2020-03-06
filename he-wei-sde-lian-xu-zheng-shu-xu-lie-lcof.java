class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> ans = new ArrayList<>();
        int l = 1, r = 1, sum = 0;
        while (l <= target / 2) {
            if (sum < target) {
                sum += r;
                r++;
            } else if (sum > target) {
                sum -= l;
                l++;
            } else {
                int[] tmp = new int[r - l + 1];
                for (int i = l; i <= r; i++) {
                    tmp[i - l] = i;
                }
                ans.add(tmp);
                sum -= l;
                l++;
            }
        }
        return ans.toArray(new int[ans.size()][]);
    }
}