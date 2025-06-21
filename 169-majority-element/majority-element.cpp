class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i, cnt = 0, canditate;
        for(i=0; i<nums.size(); i++) {
            if(cnt == 0) canditate = nums[i];

            if(nums[i] == canditate) cnt++;
            else cnt--;
        }
        return canditate;
    }
};