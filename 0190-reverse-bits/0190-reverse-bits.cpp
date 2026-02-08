class Solution {
public:
    int reverseBits(int n) {
        bitset<32> arr(n);
        for(int i=0; i<16; i++) {
            bool left = arr[i];
            bool right = arr[31-i];

            arr[31-i] = left;
            arr[i] = right;
        }
        int m = (int)arr.to_ulong();
        return m;
    }
};