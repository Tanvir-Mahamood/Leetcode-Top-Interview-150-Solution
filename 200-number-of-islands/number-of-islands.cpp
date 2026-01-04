class Solution {
public:
    bool vis[302][302];
    bool isValid(vector<vector<char>>& grid, int x, int y) {
        if(x < 0 || x >= grid.size()) return false;
        if(y < 0 || y >= grid[0].size()) return false;
        if(vis[x][y] || grid[x][y] == '0') return false;
        return true;
    }

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    void dfs(vector<vector<char>>& grid, int x, int y) {
        vis[x][y] = true;
        for(int i=0; i<4; i++) {
            if(isValid(grid, x+dx[i], y+dy[i])) {
                dfs(grid, x+dx[i], y+dy[i]);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int i, j, cnt = 0;
        for(i=0; i<grid.size(); i++) {
            for(j=0; j<grid[0].size(); j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};