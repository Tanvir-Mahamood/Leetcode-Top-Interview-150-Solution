class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row, col, starting_row, starting_col, ending_row, ending_col, total, count = 0, i;

        row = matrix.size();
        col = matrix[0].size();

        starting_row = 0;
        starting_col = 0;
        ending_row = row - 1;
        ending_col = col - 1;

        total = row * col;
        vector<int> ans(total);

        while(count < total) {
            for(i=starting_col; i<=ending_col && count < total; i++) { // go left to right
                ans[count++] = matrix[starting_row][i];
            }
            starting_row++;

            for(i=starting_row; i<=ending_row && count < total; i++) { // go up to down
                ans[count++] = matrix[i][ending_col];
            }
            ending_col--;

            for(i=ending_col; i>=starting_col && count < total; i--) { // go right to left
                ans[count++] = matrix[ending_row][i];
            }
            ending_row--;

            for(i=ending_row; i>=starting_row && count < total; i--) { // go down to up
                ans[count++] = matrix[i][starting_col];
            }
            starting_col++;
        }

        return ans;
    }
};