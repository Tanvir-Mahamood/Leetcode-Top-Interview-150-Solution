class Solution {
public:
    int jump(vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(0);
        
        int near = 0, far = 0, farthest = 0, jump = 0;

        while(far < nums.size()-1) {
            for(int i=near; i<=far; i++) {
                farthest = max(farthest, i+nums[i]);
            }

            near = far + 1;
            far = farthest;
            jump++;

        }
        return jump;
    }
};