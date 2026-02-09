class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bitCnt(32, 0);
        int ans = 0;

        for(int num: nums) {
            int j = 0;
            while(num > 0) {
                bitCnt[j++] += (num & 1);
                num = num >> 1;
            }
        }
        for(int i=0; i<32; i++) {
            bitCnt[i] %= 3;
            ans += (bitCnt[i] * (1 << i));
        }

        return ans;
    }
};