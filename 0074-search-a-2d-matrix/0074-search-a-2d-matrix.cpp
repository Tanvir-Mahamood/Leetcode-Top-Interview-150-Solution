class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i, j, r = matrix.size(), c = matrix[0].size();

        int begg = 0;
        int endd = r * c - 1;
        int midd;

        while(endd >= begg) {
            midd = begg + (endd - begg) / 2;

            if(matrix[midd/c][midd%c] == target) return true;
            else if (matrix[midd/c][midd%c] < target) begg = midd + 1;
            else endd = midd - 1;
        }

        return false;
    }
};