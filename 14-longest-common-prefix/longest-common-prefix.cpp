class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        ios::sync_with_stdio(false); cin.tie(0);
        
        string save = strs[0];
        for(int i=1; i<strs.size(); i++) {
            string temp, word = strs[i];
            for(int j=0; j<word.size(); j++) {
                if(word[j] == save[j]) temp += word[j];
                else break;
            }
            save = temp;
        }
        return save;
    }
};