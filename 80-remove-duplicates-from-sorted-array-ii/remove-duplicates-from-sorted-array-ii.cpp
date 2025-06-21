class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, idx = 1, cnt = 1;
        for(i=1; i<nums.size(); i++) {
            (nums[i] == nums[i-1]) ? cnt++ : cnt = 1;
            if(cnt <= 2) nums[idx++] = nums[i];
        }
        return idx;
    }
};