class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, buy = prices[0], profit = 0;
        for(i=1; i<prices.size(); i++) {
            if(buy < prices[i]) profit += prices[i] - buy;
            buy = prices[i];
        }
        return profit;
    }
};