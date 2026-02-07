class Solution {
public:
    int cutPoint(vector<int> &nums) {
        int begg = 0, endd = nums.size() - 1;
        int midd;
        while(begg < endd) {
            int midd = begg + (endd - begg) / 2;
            if (nums[begg] == nums[midd]) {
                break;
            }
            else if(nums[begg] < nums[midd]) {
                begg = midd;
            }
            else {
                endd = midd;
            }
        }
        return endd;
    }

    int BinarySearch(vector<int> &nums, int begg, int endd, int target) {
        while(begg <= endd) {
            int midd = begg + (endd - begg) / 2;
            if(nums[midd] == target) {
                return midd;
            }
            else if(nums[midd] < target) {
                begg = midd + 1;
            }
            else {
                endd = midd - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int cut = cutPoint(nums);
        int n = nums.size();

        if (nums[cut] == target) return cut;
        else if (nums[0] <= target) return BinarySearch(nums, 0, cut-1, target);
        else return BinarySearch(nums, cut, n-1, target);
    }
};