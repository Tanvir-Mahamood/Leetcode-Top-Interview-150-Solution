class Solution {
public:
/*
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> grid(n, INT_MAX);
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
*/
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n-1];

        for(int i=n-2; i>=0; i--) {
            for(int j=0; j<=i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }

        return dp[0];
    }
};

/*
First Solution:
Time: O(n^2)
Space: O(n^2)

Second Solution:
Time: O(n^2)
Space: O(n)

*/

