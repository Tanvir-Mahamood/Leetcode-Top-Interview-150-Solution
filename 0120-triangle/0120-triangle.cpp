class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> grid(n,vector<int>(n, INT_MAX));
        grid[0][0] = triangle[0][0];

        for(int i=1; i<n; i++) {
            for(int j=0; j<=i; j++) {
                if(j > 0) {
                    grid[i][j] = min(grid[i][j], grid[i-1][j-1] + triangle[i][j]);
                }
                if(i > j) {
                    grid[i][j] = min(grid[i][j], grid[i-1][j] + triangle[i][j]);
                }
            }
        }
        int minAns = INT_MAX;
        for(int j=0; j<n; j++) {
            minAns = min(minAns, grid[n-1][j]);
        }

        return minAns;
    }
};