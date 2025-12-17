class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int operand, operand1, operand2, result;

        for(string term: tokens) {
            if(term == "+" || term == "-" || term == "*" || term == "/") {
                operand2 = st.top();
                st.pop();
                operand1 = st.top();
                st.pop(); 

                if(term == "+") result = (operand1 + operand2);
                else if(term == "-") result = (operand1 - operand2);
                else if(term == "*") result = (operand1 * operand2);
                else if(term == "/") result = (operand1 / operand2);
                st.push(result);
            }
            else {
                operand = stoi(term);
                st.push(operand);
            }
        }
        return st.top();
    }
};