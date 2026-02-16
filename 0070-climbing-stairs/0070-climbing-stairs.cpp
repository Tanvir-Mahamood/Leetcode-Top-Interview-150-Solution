class Solution {
public:
// Bottom Up (Tabulation)
/*
    int climbStairs(int n) { 
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
*/

// Space Optimised Tabulation
/*
    int climbStairs(int n) {
        if(n <= 3) return n;

        int first = 2;
        int second = 3;
        int curr;
        for(int i=4; i<=n; i++) {
            curr = first + second;
            first = second;
            second = curr;
        }
        return curr;
    }
*/

// Top-Down Approach (Memoization)
    int solve(int n, vector<int> &dp) {
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        dp[n] = solve(n-1, dp) + solve(n-2, dp);
        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};

/*
Bottom Up (Tabulation)
Time: O(n)
Space: O(n)

Space Optimised Bottom Up (Tabulation)
Time: O(n)
Space: O(1)

Top-Down Approach (Memoization)
Time: O(n)
Space: O(n)
*/