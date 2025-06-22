class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size(), i, cnt = 0, ans = 0;
        bool mode = false;
        for(i=0; i<n; i++)
        {   
            if(s[i] == ' ') 
            {
                mode = false;
            }
            else
            {
                if(mode == false) ans = cnt, cnt = 0;
                mode = true;
                cnt++;
            }
        }
        ans = cnt;
        return ans;
    }
};