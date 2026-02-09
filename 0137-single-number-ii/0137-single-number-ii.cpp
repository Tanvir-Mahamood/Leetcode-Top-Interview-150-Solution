class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> cnt(32, 0);
        for(int num: nums) {
            bitset<32> bin(num);
            for(int i=0; i<32; i++) {
                cnt[i] = cnt[i] + (bin[i] ? 1 : 0);
            }
        }

        for(int i=0; i<32; i++) {
            cnt[i] %= 3;
        }

        bitset<32> arr;
        for(int i=0; i<32; i++) {
            arr[i] = cnt[i];
        }
        int ans = (int)arr.to_ulong();

        return ans;
    }
};