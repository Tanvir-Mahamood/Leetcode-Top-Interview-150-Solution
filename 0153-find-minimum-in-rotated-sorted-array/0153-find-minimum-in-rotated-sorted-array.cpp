class Solution {
public:
// https://leetcode.com/problems/search-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
    int cutPoint(vector<int> &nums) {
        int begg = 0, endd = nums.size() - 1, midd;
        
        while(begg < endd) {
            int midd = begg + (endd - begg) / 2;

            if (nums[begg] == nums[midd]) break;
            else if(nums[begg] < nums[midd]) begg = midd;
            else endd = midd;
        }
        if(nums[begg] > nums[endd]) return endd;
        else return 0;
    }

    int findMin(vector<int>& nums) {
        int idx = cutPoint(nums);
        return nums[idx];
    }
};