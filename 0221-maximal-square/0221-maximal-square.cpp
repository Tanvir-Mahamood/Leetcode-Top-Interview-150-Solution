class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row,vector<int>(col));
        int maxArea = 0;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(i == 0 || j == 0 || matrix[i][j] == '0') dp[i][j] = matrix[i][j] - '0';
                else dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
                maxArea = max(maxArea, dp[i][j]);
            }
        }
        return maxArea*maxArea;
    }
};