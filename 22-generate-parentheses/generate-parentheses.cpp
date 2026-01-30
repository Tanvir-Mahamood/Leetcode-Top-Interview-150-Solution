class Solution {
public:
    void helper(int open, int close, string temp, vector<string> &ans) {
        if(open == 0 && close == 0) {
            ans.push_back(temp);
            return;
        }

        if(open == close) {
            string s1 = temp + "(";
            helper(open-1, close, s1, ans);
        }
        else if(open == 0) {
            string s2 = temp + ")";
            helper(open, close-1, s2, ans);
        }
        else {
            string s1 = temp + "(";
            helper(open-1, close, s1, ans);

            string s2 = temp + ")";
            helper(open, close-1, s2, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        int open = n, close = n;
        vector<string> ans;
        string temp = "";
        helper(open, close, temp, ans);
        return ans;
    }
};