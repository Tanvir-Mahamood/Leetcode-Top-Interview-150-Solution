class Solution {
public:
// Bottop Up
/*
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX - 1);  // avoid overflow
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return (dp[amount] == INT_MAX - 1) ? -1 : dp[amount];
    }
*/

// Top Down
    int solve(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX - 1;
        if (dp[amount] != -1) return dp[amount];

        int ans = INT_MAX - 1;
        for (int coin : coins) {
            int subProb = solve(coins, amount-coin, dp);
            ans = min(ans, subProb + 1);
        }

        dp[amount] = ans;
        return ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int result = solve(coins, amount, dp);
        return (result >= INT_MAX - 1) ? -1 : result;
    }
    
};

/*
Bottop Up
Time: O(amount * no of coin)
Space: O(amount)

Top Down
Time:
Space:
*/