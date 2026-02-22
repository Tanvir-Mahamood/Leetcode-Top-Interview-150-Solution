class Solution {
public:
    bool isvalid(vector<vector<int>>& obstacleGrid, int i, int j) {
        if(i < 0 || j < 0 || obstacleGrid[i][j] == 1) return false;
        return true;
    }

    int solver(vector<vector<int>>& obstacleGrid, int x, int y, vector<vector<int>>& mem) {
        if(mem[x][y] != -1) return mem[x][y];
        
        int wayFromLeft = (isvalid(obstacleGrid, x, y-1)) ? solver(obstacleGrid, x, y-1, mem) : 0;
        int wayFromTop =  (isvalid(obstacleGrid, x-1, y)) ? solver(obstacleGrid, x-1, y, mem) : 0;
        return mem[x][y] = wayFromLeft + wayFromTop;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if(obstacleGrid[row-1][col-1] == 1) return 0;
        vector<vector<int>> mem(row, vector<int>(col, -1));
        mem[0][0] = 1;

        return solver(obstacleGrid, row-1, col-1, mem);
    }
};