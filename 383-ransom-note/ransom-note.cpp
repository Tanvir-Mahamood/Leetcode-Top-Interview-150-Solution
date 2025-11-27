class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);
        for(char ch: magazine) {
            freq[ch-'a']++;
        }
        for(char ch: ransomNote) {
            if(freq[ch-'a']) freq[ch-'a']--;
            else return false;
        }
        return true;
    }
};