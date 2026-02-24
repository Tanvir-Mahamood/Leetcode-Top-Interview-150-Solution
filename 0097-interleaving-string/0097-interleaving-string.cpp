class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if(n1 + n2 != n3) return false;
        vector<vector<bool>> grid(n1+1,vector<bool>(n2+1));

        for(int i=0; i<n1+1; i++) {
            for(int j=0; j<n2+1; j++) {
                if(i == 0 && j == 0) grid[i][j] = true;
                else if(i == 0) grid[i][j] = grid[i][j-1] && s2[j-1] == s3[i+j-1];
                else if(j == 0) grid[i][j] = grid[i-1][j] && s1[i-1] == s3[i+j-1];
                else grid[i][j] = (grid[i-1][j] && s1[i-1] == s3[i+j-1]) || (grid[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }

        return grid[n1][n2];
    }
};

/*

grid:
      0 1 2 3 4 5
        d b b c a 
      _ _ _ _ _ _
0   | 1 1 1 1 1 1
1 a | 1 1 0 0 0 0
2 a | 1 1 1 1 1 0
3 b | 1 1 1 0 1 0
4 c | 1 0 1 1 1 1
5 c | 1 0 0 1 0 1


*/