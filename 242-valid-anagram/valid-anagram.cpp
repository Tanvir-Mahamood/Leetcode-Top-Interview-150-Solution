class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> freq(26, 0);
        for(char ch: s) {
            int idx = ch - 'a';
            freq[idx]++;
        }
        for(char ch: t) {
            int idx = ch - 'a';
            freq[idx]--;
            if(freq[idx] < 0) return false;
        }

        for(int i=0; i<26; i++) {
            if(freq[i] != 0) return false;
        }
        return true;
    }
};