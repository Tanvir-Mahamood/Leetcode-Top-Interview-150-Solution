class Solution {
public:
    string makeString(vector<int>& nums, int l, int r) {
        string str;
        if(l == r) str = to_string(nums[l]);
        else str = to_string(nums[l]) + "->" + to_string(nums[r]);
        return str;
    }

    vector<string> summaryRanges(vector<int>& nums) {
        int lft = 0, rgt = 1;
        vector<string> ans;
        if(nums.size() == 0) return ans;
        string run;

        while(rgt < nums.size()) {
            if(nums[rgt] == nums[rgt-1] + 1) rgt++;
            else {
                run = makeString(nums, lft, rgt-1);
                ans.push_back(run);
                
                lft = rgt;
                rgt += 1;
            }
        }

        run = makeString(nums, lft, nums.size()-1);
        ans.push_back(run);

        return ans;
    }
};