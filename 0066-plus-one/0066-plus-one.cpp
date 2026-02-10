class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int n = digits.size(), carry = 0, sum = 0;

        sum = (digits[n-1] < 9) ? digits[n-1] + 1 : 0;
        if(sum == 0) carry = 1;
        ans.push_back(sum);

        for(int i=n-2; i>=0; i--) {
            sum = digits[i] + carry;
            if(sum == 10) {
                sum = 0;
                carry = 1;
            }
            else {
                carry = 0;
            }
            ans.push_back(sum);
        }
        if(carry) ans.push_back(carry);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};