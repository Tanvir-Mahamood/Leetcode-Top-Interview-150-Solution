class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();

        vector<bool> dp(len+1, false);
        dp[0] = true;

        for(int i=1; i<=len; i++) {
            for(string term: wordDict) {
                int start = i - term.size();
                if(start >= 0 && dp[start] && s.substr(start, term.size()) == term) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};