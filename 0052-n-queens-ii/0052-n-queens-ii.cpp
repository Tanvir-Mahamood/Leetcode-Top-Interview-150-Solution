class Solution {
private:
    bool isSafe(vector<string> &board, int row, int col, int n) {
        for(int j=0; j<n; j++) { // horizontal check 
            if(board[row][j] == 'Q') {
                return false;
            }
        }

        for(int i=0; i<n; i++) { // vertical check 
            if(board[i][col] == 'Q') {
                return false;
            }
        }

        for(int i=row, j=col; i>=0 && j>=0; i--, j--) { // left-diagonal check 
            if(board[i][j] == 'Q') {
                return false;
            }
        }

        for(int i=row, j=col; i>=0 && j<n; i--, j++) { // right-diagonal check 
            if(board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void nQueen(vector<string> &board, int row, int n, int &cnt) {
        if(row == n) {
            cnt++;
            return;
        }

        for(int j=0; j<n; j++) {
            if(isSafe(board, row, j, n)) {
                board[row][j] = 'Q';
                nQueen(board, row+1, n, cnt);
                board[row][j] = '.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int cnt = 0;

        nQueen(board, 0, n, cnt);
        return cnt;
    }
};

// Inspired From: https://leetcode.com/problems/n-queens/description/