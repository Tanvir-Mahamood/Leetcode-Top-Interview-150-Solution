class Solution {
public:
    int calculate(string s) {
        stack<int> memory;
        long result = 0, current = 0;
        int sign = 1;
        for(char ch: s) {
            if(isdigit(ch)) {
                current = current * 10 + (ch-'0');
            }
            else if(ch == '+') {
                result += current * sign;
                sign = 1;
                current = 0;
            }
            else if(ch == '-') {
                result += current * sign;
                sign = -1;
                current = 0;
            }
            else if(ch == '(') {
                memory.push(result);
                memory.push(sign);
                result = 0;
                // current = 0;
                sign = 1;
            }
            else if(ch == ')') {
                result += current * sign;
                current = 0;

                result *= memory.top(); // result = (result) * sign
                memory.pop();
                result += memory.top(); // result = result + sign * (result)
                memory.pop();
            }
        }
        result += current * sign;
        return result;
    }
};