class Solution {
public:
    int getDigitFromRight(int num, int idx) {
        while(idx--) {
            num /= 10;
        }
        return (num % 10);
    }

    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10) return true;

        int len = log10(x) + 1;
        for(int i=0; i<len/2; i++) {
            int rightDigit = getDigitFromRight(x, i);
            int leftDigit = getDigitFromRight(x, len-1-i);
            if(leftDigit != rightDigit) return false;
        }
        return true;
    }
};