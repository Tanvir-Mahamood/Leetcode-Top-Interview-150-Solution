class Solution {
public:
    int m, n;

    bool isValid(int i, int j) {
        return (0 <= i && i < m && 0 <= j && j < n);      
    }

    int cntLiveNeighbor(vector<vector<int>>& board, int a, int b) {
        int i, j, neighbor, cnt = 0;
        for(i=-1; i<2; i++) {
            for(j=-1; j<2; j++) {
                if(!(i | j)) continue;
        
                if(isValid(a+i, b+j)) neighbor = board[a+i][b+j];
                else continue;

                if(neighbor >= 1) cnt++;
            }
        }
        return cnt;
    }

    int nextState(vector<vector<int>>& board, int a, int b) {
        int cnt = cntLiveNeighbor(board, a, b);
        if(board[a][b]) {
            if(cnt == 2 || cnt == 3) return 2; // next state is live
            else return 3;                     // next state is die
        }
        else {
            if(cnt == 3) return -2; // next state is live
            else return -3;         // next state is live
        }
    }

    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();

        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                board[i][j] = nextState(board, i, j);
            }
        }

        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                board[i][j] = 3 - abs(board[i][j]);
            }
        }
    }
};

/*
The cell is initially in live state(1), 
    if it lives, then it is converted to 2
    if it dies, then it isconverted to 3

The cell is initially in die state(0), 
    if it lives, then it is converted to -2
    if it dies, then it isconverted to -3
*/