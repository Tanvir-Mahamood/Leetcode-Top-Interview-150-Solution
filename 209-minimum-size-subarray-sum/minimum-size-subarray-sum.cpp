class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i, n = nums.size();
        vector<int> prefSum(n+1);
        prefSum[0] = 0;
        for(i=1; i<=n; i++) {
            prefSum[i] = prefSum[i-1] + nums[i-1];
        }
        int lft = 0, rgt = 1, val, len = 100005;
        while(lft <= rgt && rgt <= n) {
            val = prefSum[rgt] - prefSum[lft];
            if(val >= target) {
                len = min(len, (rgt-lft));
                lft++;
            }
            else rgt++;
        }
        return (len == 100005) ? 0 : len;
    }
};