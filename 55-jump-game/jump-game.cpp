class Solution {
public:
    bool canJump(vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(0);
        
        int near = 0, far = 0, farthest = 0;
        bool flag = false;

        while(near <= far) {
            for(int i=near; i<=far; i++) {
                farthest = max(farthest, i+nums[i]);
            }

            near = far + 1;
            far = farthest;

            if(far >= nums.size()-1) {
                flag = true;
                break;
            }
        }
        return flag;
    }
};