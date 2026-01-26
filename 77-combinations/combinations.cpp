class Solution {
public:
    vector<vector<int>> ans;

    void helper(int level, vector<int> temp, int num, int n, int k) {
        int next_level = level + 1;

        if(level != -1) temp.push_back(num);

        if(next_level >= k) {
            ans.push_back(temp);
            return;
        }

        for(int i=num+1; i<=n; i++) {
            helper(next_level, temp, i, n, k);
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        int num = 0;
        helper(-1, temp, num, n, k);
        return ans;
    }
};