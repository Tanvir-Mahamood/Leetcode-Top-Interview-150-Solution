class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i, j, k, n = nums.size();

        for(i=0; i<n; i++) {
            if(i>0 && nums[i] == nums[i-1]) continue;
            j = i + 1;
            k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0) j++;
                else if (sum > 0) k--;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};