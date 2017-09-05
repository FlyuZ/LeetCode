class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit = 0, lenth = prices.size() -1;
        for(int i=0; i<lenth; i++)
        {
            if(prices[i] < prices[i+1])
                profit += prices[i+1] - prices[i];
        }
        return profit;
    }
};
