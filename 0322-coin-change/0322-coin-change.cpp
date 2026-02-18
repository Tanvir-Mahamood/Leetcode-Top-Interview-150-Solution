class Solution {
public:
// Bottop Up
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

// Top Down
/*
    int solve(vector<int>& coins, int amount, vector<int> &dp) {
        if(amount == 0) return 0;

        for(int coin: coins) {
            if(n-coin >= 0) {
                int subProb = solve(coins, n-coin, dp);
                if(subProb != INT_MAX) {
                    dp[n] = min(dp[n], subProb+1);
                }
            }
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<bool> dp(amount+1, INT_MAX);
        return solve(coins, amount, dp);
    }
    */
};

/*
Bottop Up
Time: O(amount * no of coin)
Space: O(amount)

Top Down
Time:
Space:
*/