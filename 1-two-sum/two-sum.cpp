class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) {
            int token = target - nums[i];
            if(mp.count(token)) return {i, mp[token]};
            mp[nums[i]] = i;
        }
        return {};
    }
};