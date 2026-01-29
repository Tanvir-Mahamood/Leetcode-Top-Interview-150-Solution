class Solution {
public:
    set<vector<int>> st;

    void backtrack(int index, vector<int>& arr, int target, vector<int> &combination, vector<vector<int>> &ans) {
        if(index == arr.size() || target < 0) {
            return;
        }
        if(target == 0) {
            if(st.find(combination) == st.end()) {
                ans.push_back(combination);
                st.insert(combination);
            }
            return;
        }

        combination.push_back(arr[index]);
        backtrack(index+1, arr, target-arr[index], combination, ans);
        backtrack(index, arr, target-arr[index], combination, ans);
        combination.pop_back();
        backtrack(index+1, arr, target, combination, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        backtrack(0, candidates, target, comb, ans);
        return ans;
    }
};

/*
from a node, we have 3 options
    - take a single element & go for next
    - take that element and stay here for reuse
    - skip the element & go for next
*/