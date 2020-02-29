class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[] ans = new int[n];
        for (List<Integer> i : triangle) {
            for (int j = i.size() - 1; j >= 0; j--) {
                if (j == 0)
                    ans[j] += i.get(j);
                else if (j == i.size() - 1)
                    ans[j] = i.get(j) + ans[j - 1];
                else
                    ans[j] = i.get(j) + Math.min(ans[j], ans[j - 1]);
            }
        }
        int min = 99999;
        for (int i = 0; i < n; i++) {
            if (min > ans[i])
                min = ans[i];
        }
        return min;
    }
}