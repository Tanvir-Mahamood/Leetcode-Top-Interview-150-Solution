class Solution {
public:
// Bottom Up (Tabulation)
/*
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[1], dp[0]);
        for(int i=2; i<n; i++) {
            dp[i] = max((nums[i]+dp[i-2]), dp[i-1]);
        }
        return dp[n-1];
    }
*/

// Space Optimised Bottom Up (Tabulation)
/*
    int rob(vector<int>& nums) {
        int first = 0;
        int second = 0;
        int curr;

        for(int num: nums) {
            curr = max((num+first), second);
            first = second;
            second = curr;
        }
        return curr;
    }
*/

// Top-Down Approach (Memoization)
    int solve(vector<int> &nums, int pos, vector<int> &dp) {
        if(pos == 0) return nums[pos];
        if(pos < 0) return 0;
        if(dp[pos] != -1) return dp[pos];

        int pick = nums[pos] + solve(nums, pos-2, dp); // if we pick the current element
        int not_pick = solve(nums, pos-1, dp); // if not...

        return dp[pos] = max(pick, not_pick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, n-1, dp);
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