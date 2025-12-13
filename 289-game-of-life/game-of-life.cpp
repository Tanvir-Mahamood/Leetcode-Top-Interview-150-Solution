class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        if(i<0 || i >= m) return false;
        if(j<0 || j >= n) return false;
        return true;
    }

    int dx[3] = {-1, 0, 1};
    int dy[3] = {-1, 0, 1}; 

    int nextState(vector<vector<int>>& board, int a, int b) {
        int m = board.size(), n = board[0].size(), i, j, neighbor_x, neighbor_y, neighbor, cnt = 0;

        if(board[a][b]) {
            for(i=-1; i<2; i++) {
                for(j=-1; j<2; j++) {
                    if(i == 0 && j == 0) continue;
                    neighbor_x = a + i;
                    neighbor_y = b + j;
                    
                    if(isValid(neighbor_x, neighbor_y, m, n)) {
                        neighbor = board[neighbor_x][neighbor_y];
                    }
                    else continue;

                    if(neighbor >= 1) cnt++;
                }
            }

            if(cnt == 2 || cnt == 3) return 2; // next state is live
            else return 3; // next state is die
        }
        else {
            for(i=-1; i<2; i++) {
                for(j=-1; j<2; j++) {
                    if(i == 0 && j == 0) continue;
                    neighbor_x = a + i;
                    neighbor_y = b + j;
                    
                    if(isValid(neighbor_x, neighbor_y, m, n)) {
                        neighbor = board[neighbor_x][neighbor_y];
                    }
                    else continue;

                    if(neighbor >= 1) cnt++;
                }
            }
            if(cnt == 3) return -2;
            else return -3;
        }
    }

    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                board[i][j] = nextState(board, i, j);
            }
        }

        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(abs(board[i][j]) == 2) board[i][j] = 1;
                else if(abs(board[i][j]) == 3) board[i][j] = 0;
            }
        }
    }
};