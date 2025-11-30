class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> mpp(256, -1), used(256, 0);
        int i, ch1, ch2;
        for(i=0; i<s.length(); i++) {
            ch1 = static_cast<int>(s[i]);
            ch2 = static_cast<int>(t[i]);

            if(mpp[ch1] == -1 && used[ch2] == 0) mpp[ch1] = ch2, used[ch2]++;
            else if(mpp[ch1] == -1 && used[ch2] != 0) return false;
            else if(mpp[ch1] != -1 && mpp[ch1] != ch2) return false;
        }
        return true;
    }
};