class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row, col, starting_row, starting_col, ending_row, ending_col, total, count = 0, i;

        row = matrix.size();
        col = matrix[0].size();

        starting_row = 0;
        starting_col = 0;
        ending_row = row - 1;
        ending_col = col - 1;

        total = row * col;

        while(count < total) {
            // go left to right
            for(i=starting_col; i<=ending_col && count < total; i++) {
                ans.push_back(matrix[starting_row][i]);
                count++;
            }
            starting_row++;

            // go up to down
            for(i=starting_row; i<=ending_row && count < total; i++) {
                ans.push_back(matrix[i][ending_col]);
                count++;
            }
            ending_col--;

            // go right to left
            for(i=ending_col; i>=starting_col && count < total; i--) {
                ans.push_back(matrix[ending_row][i]);
                count++;
            }
            ending_row--;

            // go down to up
            for(i=ending_row; i>=starting_row && count < total; i--) {
                ans.push_back(matrix[i][starting_col]);
                count++;
            }
            starting_col++;
        }

        return ans;
    }
};