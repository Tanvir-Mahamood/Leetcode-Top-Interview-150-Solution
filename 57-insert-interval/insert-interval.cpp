class Solution {
public:
    // https://leetcode.com/problems/merge-intervals/?envType=study-plan-v2&envId=top-interview-150
    vector<vector<int>> merge(vector<vector<int>>& intervals) { 
        // sort(intervals.begin(), intervals.end());
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

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0, n = intervals.size(), j = 0;
        vector<vector<int>> result(n+1);

        bool inserted = false;

        for (vector<int> element : intervals) {
            if (!inserted && newInterval[0] <= element[0]) {
                result[j++] = newInterval;
                inserted = true;
            }
            result[j++] = element;
        }

        if (!inserted) {
            result[j] = newInterval;
        }

        vector<vector<int>> ans = merge(result);
        return ans;
    }
};