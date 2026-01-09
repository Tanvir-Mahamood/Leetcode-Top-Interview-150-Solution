/*
[
    [-1,-1,-1,-1,-1,-1],
    [-1,-1,-1,-1,-1,-1],
    [-1,-1,-1,-1,-1,-1],
    [-1,35,-1,-1,13,-1],
    [-1,-1,-1,-1,-1,-1],
    [-1,15,-1,-1,-1,-1]
]


36 35 34 33 32 31
25 26 27 28 29 30
24 23 22 21 20 19
13 14 15 16 17 18
12 11 10 09 08 07
01 02 03 04 05 06

*/

class Solution {
public:
    void bfs(int posVal, vector<int> &minRolls, int n, vector<vector<int>>& board) {
        minRolls[posVal] = 0; // at pos 1, we can stand without rolling
        queue<int> q;
        q.push(posVal);

        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(int i=1; i<=6 && curr+i<=n*n; i++) { // dice moving [1,6]
                int next = curr + i;

                int row = (next - 1) / n;
                int col = (next - 1) % n;

                int actualRow = n - 1 - row;
                int actualCol = (row & 1) ? n - 1 - col : col;

                // ladder or snack adjustment
                int val = (board[actualRow][actualCol] == -1) ? next : board[actualRow][actualCol];

                if(minRolls[val] == -1) {
                    minRolls[val] = minRolls[curr] + 1;
                    q.push(val);
                }
            }
        }
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> minRolls(n*n+1, -1);
        bfs(1, minRolls, n, board);
        return minRolls.back();
    }
};