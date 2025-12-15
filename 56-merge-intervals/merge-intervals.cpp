class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> temp(2), current = intervals[0];
        current.resize(2);
        vector<vector<int>> ans;

        for(int i=1; i<intervals.size(); i++) {
            temp = intervals[i];
            if(current[1] >= temp[0]) {
                current[1] = max(current[1], temp[1]);
            }
            else {
                ans.push_back(current);
                current = intervals[i];
            }
        }
        ans.push_back(current);

        return ans;
    }
};