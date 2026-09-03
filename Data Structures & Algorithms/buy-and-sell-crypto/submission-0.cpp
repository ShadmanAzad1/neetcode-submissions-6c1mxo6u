class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minprice = prices[0];
        for(int i = 0; i < prices.size(); i++)
        {
            if(minprice > prices[i])
            {
                minprice = prices[i];
            }

            if(maxprofit < prices[i] - minprice)
            {
                maxprofit = prices[i] - minprice;
            }
        }

        return maxprofit;
    }
};
