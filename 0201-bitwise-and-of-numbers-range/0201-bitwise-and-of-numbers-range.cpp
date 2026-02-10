class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int availableStep = right - left;
        int bitPos = 0, ans = 0, num = left;
        while(left > 0) {
            int requiredStep;
            if(left & 1) {
                requiredStep = (1 << bitPos) - (num & ((1 << bitPos) - 1));
                if(requiredStep > availableStep) {
                    ans += (1 << bitPos);
                }
            }
            left = left >> 1;
            bitPos++;
        }
        return ans;
    }
};

/*
requiredStep = amount of steps required to set a bit 0 for a specific bit position
for example

    0(1)01
    if you add +3, (3 steps) => the bracketed bit will be converted to 0

    we can do it for eachj bits

 Formula: 
    requiredStep = (2^bitPos) - left % (2^bitPos)
*/