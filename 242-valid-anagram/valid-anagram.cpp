class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> freq(26, 0);
        for(int i=0; i<s.size(); i++) {
            int ch1 = s[i] - 'a';
            int ch2 = t[i] - 'a';
            freq[ch1]++;
            freq[ch2]--;
        }
        for(int i=0; i<26; i++) {
            if(freq[i] != 0 ) return false;
        }
        return true;
    }
};