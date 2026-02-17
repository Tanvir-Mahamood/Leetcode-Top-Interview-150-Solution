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
};

/*
Bottom Up (tabular)
Time: O(n)
Space: O(n)

Space Optimised Bottom Up (tabular)
Time: O(n)
Space: O(1)
*/