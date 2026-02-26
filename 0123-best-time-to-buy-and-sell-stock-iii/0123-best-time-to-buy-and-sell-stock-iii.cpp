class Solution {
private:
    int solver(int idx, int canBuy, int limit, vector<int>& prices, vector<vector<vector<int>>> &dp) {
        if(idx == prices.size()) return 0;
        if(limit == 0) return 0;
        if(dp[idx][canBuy][limit] != -1) return dp[idx][canBuy][limit];
        int profit = 0;
        if(canBuy) {
            int buy = - prices[idx] + solver(idx+1, 0, limit, prices, dp);
            int not_buy = solver(idx+1, 1, limit, prices, dp);
            profit = max(buy, not_buy);
        }
        else {
            int sell = prices[idx] + solver(idx+1, 1, limit-1, prices, dp);
            int not_sell = solver(idx+1, 0, limit, prices, dp);
            profit = max(sell, not_sell);
        }
        return dp[idx][canBuy][limit] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1))); // n * 2 * 3
        return solver(0, 1, 2, prices, dp);
    }
};