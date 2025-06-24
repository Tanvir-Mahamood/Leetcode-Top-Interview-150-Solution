class Solution {
public:
    int strStr(string haystack, string needle) {
        ios::sync_with_stdio(false); cin.tie(0);
        
        if(haystack.size() < needle.size()) return -1;
        for(int i=0; i+needle.size()<=haystack.size(); i++) {
            if(haystack.substr(i, needle.size()) == needle) return i;
        }
        return -1;
    }
};