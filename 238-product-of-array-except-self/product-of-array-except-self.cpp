class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(0);
        
        int i, n = nums.size(), right = 1;
        vector<int> answer(n);
        answer[0] = 1;
        for(i=1; i<n; i++) answer[i] = answer[i-1] * nums[i-1];
        for(i=n-1; i>=0; i--) answer[i] *= right, right *= nums[i];
        return answer;
    }
};