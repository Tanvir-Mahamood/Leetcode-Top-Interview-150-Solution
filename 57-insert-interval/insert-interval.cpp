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
        int i, n = intervals.size();
        vector<vector<int>> arr(n+1);

        if(n == 0) arr[0] = newInterval;
        
        for(i=0; i<n; i++) {
            if(intervals[i][0] < newInterval[0]) arr[i] = intervals[i];
            else {
                arr[i] = newInterval;
                break;
            } 
        }

        if(i == n) arr[i] = newInterval;

        for(; i<n; i++) {
            arr[i+1] = intervals[i];
        }

        vector<vector<int>> ans = merge(arr);
        return ans;
    }
};