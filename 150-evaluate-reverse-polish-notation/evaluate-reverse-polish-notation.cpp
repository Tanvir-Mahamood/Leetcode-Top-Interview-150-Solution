class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans = 0;
        for(string term: tokens) {
            if(term == "+" || term == "-" || term == "*" || term == "/") {
                int operand2 = st.top();
                st.pop();
                int operand1 = st.top();
                st.pop(); 
                int result;
                if(term == "+") result = (operand1 + operand2);
                else if(term == "-") result = (operand1 - operand2);
                else if(term == "*") result = (operand1 * operand2);
                else if(term == "/") result = (operand1 / operand2);
                st.push(result);
            }
            else {
                int operand = stoi(term);
                st.push(operand);
            }
        }
        return st.top();
    }
};