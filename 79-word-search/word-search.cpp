class Solution {
public:
    bool isValid(int x, int y, vector<vector<char>>& board) {
        if(x < 0 || x >= board.size()) return false;
        if(y < 0 || y >= board[0].size()) return false;
        if(board[x][y] == '*') return false;
        return true;
    }

    int dx[4] = {1, -1, 0 ,0};
    int dy[4] = {0, 0, 1, -1};   

    bool bt(int x, int y, vector<vector<char>>& board, string word, int index) {
        if(index == word.size()) return true;
        char ch = board[x][y];
        board[x][y] = '*';

        for(int i=0; i<4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if(isValid(new_x, new_y, board) && board[new_x][new_y] == word[index]) {
                if(bt(new_x, new_y, board, word, index+1)) {
                    board[x][y] = ch;
                    return true;
                }
            }
        }

        board[x][y] = ch;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j] == word[0] && bt(i, j, board, word, 1)) return true;
            }
        }
        return false;
    }
};