class Solution {
public:
    vector<vector<int>> ans;

    void helper(int level, vector<int> temp, int num, int n, int k) {
        if(num != 0) temp.push_back(num);

        if(level+1 >= k) {
            ans.push_back(temp);
            return;
        }

        for(int i=num+1; i<=n; i++) {
            helper(level+1, temp, i, n, k);
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        int num = 0;
        helper(-1, temp, 0, n, k);
        return ans;
    }
};