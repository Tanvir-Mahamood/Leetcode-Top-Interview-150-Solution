class Solution {
/*
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
*/

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // -> Approach1: Recursive with Memoization
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1))); // n * 2 * 3
        // return solver(0, 1, 2, prices, dp); 

        // -> Approach2: Tabulation
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3, 0))); // (n+1) * 2 * 3

        for(int idx=0; idx<n; idx++) { // handling base case: if(limit == 0) return 0;
            for(int canBuy=0; canBuy<=1; canBuy++) {
                dp[idx][canBuy][0] = 0;
            }
        }

        for(int canBuy=0; canBuy<=1; canBuy++) { // handling base case: if(idx == prices.size()) return 0;
            for(int limit=0; limit<=2; limit++) {
                dp[n][canBuy][limit] = 0;
            }
        }

        for(int idx=n-1; idx>=0; idx--) {
            for(int canBuy=0; canBuy<=1; canBuy++) {
                for(int limit=1; limit<=2; limit++) {
                    if(canBuy == 1) {
                        int buy = - prices[idx] + dp[idx+1][0][limit];
                        int not_buy = dp[idx+1][1][limit];
                        dp[idx][canBuy][limit] = max(buy, not_buy);
                    }
                    else {
                        int sell = prices[idx] + dp[idx+1][1][limit-1];
                        int not_sell = dp[idx+1][0][limit];
                        dp[idx][canBuy][limit] = max(sell, not_sell);
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};

/*
-> Approach1: Recursive with Memoization
Total state: n * 2 * 3
Time Complexity = O(n)

dp[n][2][3] and Auxilary stack space: n
Space Complexity: O(n)

-> Approach2: Tabulation
Total iteration: n * 2 * 3
Time Complexity: O(n)
Space Complexity: O(n)
*/