class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        if(k >= n/2) {
            int profit = 0;
            for(int i=1; i<n; i++) {
                if(prices[i] > prices[i-1]) {
                    profit += (prices[i] - prices[i-1]);
                }
            }
            return profit;
        }
        
        vector<vector<int>> after(2, vector<int> (k+1, 0)); 
        vector<vector<int>> current(2, vector<int> (k+1, 0)); 

        for(int idx=n-1; idx>=0; idx--) {
            for(int canBuy=0; canBuy<=1; canBuy++) {
                for(int limit=1; limit<=k; limit++) {
                    if(canBuy == 1) {
                        int buy = - prices[idx] + after[0][limit];
                        int not_buy = after[1][limit];
                        current[canBuy][limit] = max(buy, not_buy);
                    }
                    else {
                        int sell = prices[idx] + after[1][limit-1];
                        int not_sell = after[0][limit];
                        current[canBuy][limit] = max(sell, not_sell);
                    }
                }
            }
            after = current;
        }

        return after[1][k];
    }
};