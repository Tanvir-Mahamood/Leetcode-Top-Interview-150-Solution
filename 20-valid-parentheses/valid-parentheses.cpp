class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch: s) {
            if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else if(st.size() == 0) return false;
            else {
                char top = st.top();
                if(ch == ')' && top != '(') return false;
                if(ch == '}' && top != '{') return false;
                if(ch == ']' && top != '[') return false;

                st.pop();
            }
        }

        if(st.size()) return false;
        return true;
    }
};