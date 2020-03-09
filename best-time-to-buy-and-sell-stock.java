class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length <= 1)
            return 0;
        int ans = 0;
        int min = prices[0];
        for (int i = 1; i < prices.length; i++) {
            ans = Math.max(ans, prices[i] - min);
            min = Math.min(min, prices[i]);
        }
        return ans;
    }
}