class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i,j, n = matrix.size();
        int top = 0, bottom = n-1;

        // vertically reversed
        while(top < bottom) {
            for(j=0; j<n; j++) {
                swap(matrix[top][j], matrix[bottom][j]);
            }
            top++;
            bottom--;
        }

        // transpose matrix
        for(i=0; i<n; i++) {
            for(j=i+1; j<n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};