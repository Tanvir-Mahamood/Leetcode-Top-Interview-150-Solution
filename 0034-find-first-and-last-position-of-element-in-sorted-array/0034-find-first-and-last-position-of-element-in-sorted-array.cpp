class Solution {
public:
    int BinarySearch(vector<int>& nums, int target, bool isLeftScanning) {
        int begg = 0, endd = nums.size() - 1, midd, idx = -1;
        while(begg <= endd) {
            midd = begg + (endd - begg) / 2;

            if(nums[midd] == target) {
                idx = midd;
                if(isLeftScanning) {
                    endd = midd - 1;
                }
                else {
                    begg = midd + 1;
                }
            }
            else if(nums[midd] < target) {
                begg = midd + 1;
            }
            else {
                endd = midd - 1;
            }
        }
        return idx;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = BinarySearch(nums, target, true);
        int right = BinarySearch(nums, target, false);

        vector<int> ans(2);
        ans[0] = left;
        ans[1] = right;

        return ans;
    }
};