class Solution {
    public int coinChange(int[] coins, int amount) {
        if (coins.length == 0)
            return -1;
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, 1, dp.length, amount + 1);
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.length; j++) {
                if (coins[j] <= i) {
                    dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        if (dp[amount] > amount)
            return -1;
        else
            return dp[amount];
    }
}