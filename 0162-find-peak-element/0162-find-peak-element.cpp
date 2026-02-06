class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left < right) {
            int midd = left + (right - left) / 2;
            if(nums[midd] < nums[midd+1]) { // mid-point is in upward slope
                left = midd + 1;
            }
            else { // mid-point is in downward slope
                right = midd;
            }
        }
        return left;
    }
};