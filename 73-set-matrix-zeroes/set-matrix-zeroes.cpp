class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row, col;
        int i, j;
        for(i=0; i<matrix.size(); i++) {
            for(j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(int r: row) {
            for(j=0; j<matrix[0].size(); j++) matrix[r][j] = 0;
        }
        for(int c: col) {
            for(i=0; i<matrix.size(); i++) matrix[i][c] = 0;
        }
    }
};