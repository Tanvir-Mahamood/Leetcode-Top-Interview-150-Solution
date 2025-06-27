class Solution {
public:
    bool is_safe(vector<int> &freq, char ch, int i, int j) {
        if(!freq[ch-'0']) {
            freq[ch-'0'] = 1;
            return true;
        }
        return false;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int i, j, k, l, I, J;

        for(i=0; i<9; i++) { // row operation
            vector<int> freq(10, 0);
            for(j=0; j<9; j++) {
                if(board[i][j] != '.' && !is_safe(freq, board[i][j], i, j)) return false;
            }
        }

        for(j=0; j<9; j++) { // col operation
            vector<int> freq(10, 0);
            for(i=0; i<9; i++) {
                if(board[i][j] != '.' && !is_safe(freq, board[i][j], i, j)) return false;
            }
        }

        for(i=0; i<9; i+=3) { // cell operation
            for(j=0; j<9; j+=3) {
                vector<int> freq(10, 0);
                for(k=0; k<3; k++) {
                    for(l=0; l<3; l++) {
                        I = i + k;
                        J = j + l;
                        if(board[I][J] != '.' && !is_safe(freq, board[I][J], I, J)) return false;
                    }
                }
            }
        }
        return true;
    }
};