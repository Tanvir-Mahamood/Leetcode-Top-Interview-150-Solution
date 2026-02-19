class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> list;
        for(int num: nums) {
            int idx = lower_bound(list.begin(), list.end(), num) - list.begin();
            if(idx == list.size()) list.push_back(num);
            else list[idx] = num;
        }
        return list.size();
    }
};