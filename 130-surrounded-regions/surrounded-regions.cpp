class Solution {
public:
    int n, m;
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    bool isValid(int x, int y, vector<vector<char>>& board) {
        if(x < 0 || x >= n) return false;
        if(y < 0 || y >= m) return false;
        if(board[x][y] != 'O') return false;
        return true;
    }

    void dfs(int x, int y, vector<vector<char>>& board) {
        board[x][y] = '#';
        for(int i=0; i<4; i++) {
            if(isValid(x+dx[i], y+dy[i], board)) {
                dfs(x+dx[i], y+dy[i], board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        // visiting first & last rows
        for(int j=0; j<m; j++) {
            if(board[0][j] == 'O') dfs(0, j, board);
            if(board[n-1][j] == 'O') dfs(n-1, j, board);
        }

        // visiting first & last cols
        for(int i=0; i<n; i++) {
            if(board[i][0] == 'O') dfs(i, 0, board);
            if(board[i][m-1] == 'O') dfs(i, m-1, board);
        }

        // Transformation
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};