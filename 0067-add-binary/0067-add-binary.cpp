class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size(), n2 = b.size(), c_in = 0;
        string ans = "";

        while(n1 > 0 || n2 > 0) {
            int digit1 = (n1 > 0) ? a[n1-1] - '0' : 0;
            int digit2 = (n2 > 0) ? b[n2-1] - '0' : 0;

            int sum = digit1 + digit2 + c_in;

            ans = (char)((sum % 2) + '0') + ans;
            c_in = sum / 2;

            n1--;
            n2--;
        }
        if(c_in) ans = (char)(c_in + '0') + ans;

        return ans;
    }
};