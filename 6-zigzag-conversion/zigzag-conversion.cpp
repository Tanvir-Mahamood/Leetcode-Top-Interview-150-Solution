class Solution {
public:
    string convert(string str, int numRows) {

        if (numRows == 1) {
            return str;
        }

        int len=int(str.length());
    //int seg=ceil((double)len/(2*numRows-2));
    int seg=ceil(len / (2 * numRows - 2.0));
    int numCols=seg*(numRows-1);
    char grid[numRows][numCols];
    memset(grid,' ',sizeof(grid));
    string ans;

    int r,c,k;
    r=c=k=0;
    while(k<len)
    {
        while(r<numRows && k<len) //Down
        {
            grid[r][c]=str[k];
            r++;
            k++;
        }
        r-=2;
        c++;

        while(r>0 && k<len && c<numCols)
        {
            grid[r][c]=str[k];
            r--;
            c++;
            k++;
        }
    }

    for(r=0; r<numRows; r++)
    {
        for(c=0; c<numCols; c++)
        {
            if(grid[r][c] != ' ')ans+=grid[r][c];
        }
    }
    return ans;
    }
};