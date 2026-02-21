class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row,vector<int>(col, INT_MAX));
        dp[0][0] = grid[0][0];

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(j > 0) {
                    dp[i][j] = min(dp[i][j], grid[i][j]+dp[i][j-1]);
                }
                if(i > 0) {
                    dp[i][j] = min(dp[i][j], grid[i][j]+dp[i-1][j]);
                }
            }

        }
        return dp[row-1][col-1];
    }
};