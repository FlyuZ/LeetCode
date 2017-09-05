//方法一：动态规划，分别计算前0-i天的最大值和后i-lenth天的最大值
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int lenth = prices.size();
        if(lenth <=1)
            return 0;
        else
        {
            vector<int> lprofit(lenth);
            vector<int> rprofit(lenth);
            int minp = prices[0];
            lprofit[0] = 0;
            for(int i=1; i<lenth; i++)
            {
                if(minp >= prices[i])
                {
                    minp = prices[i];
                    lprofit[i] = lprofit[i-1];
                }
                else if(prices[i] - minp > lprofit[i-1])
                    lprofit[i] = prices[i] - minp;
            }
            int maxp = prices[lenth-1];
            rprofit[lenth-1] = 0;
            for(int i=lenth-2; i>=0; i--)
            {
                if(maxp <= prices[i])
                {
                    maxp = prices[i];
                    rprofit[i] = rprofit[i+1];
                }
                else if(maxp - prices[i] > rprofit[i+1])
                    rprofit[i] = maxp - prices[i];
            }
            int ans=0;
            for(int i=0; i<lenth; i++)
            {
                if(ans < lprofit[i] + rprofit[i])
                    ans = lprofit[i] + rprofit[i];
            }
            return ans;
        }
        return 0;
    }
};

//ans[]是当前到达第i天可以最多进行j次交易，最好的利润是多少
//tmp[]是当前到达第i天，最多可进行j次交易，并且最后一次交易在当天卖出的最好的利润是多少
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty()) 
            return 0;
        int ans[3] = {0};
        int tmp[3] = {0};
        for (int i=0; i<prices.size()-1; i++)
        {
            int diff = prices[i+1] - prices[i];
            for (int j=2; j>=1; j--)
            {
                tmp[j] = max(ans[j-1] + max(diff, 0), tmp[j] + diff);
                ans[j] = max(tmp[j], ans[j]);
            }
        }
        return ans[2];
    }
};
