class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        for(int i=5; n/i>=1; i*=5) {
            cnt += (n / i);
        }
        return cnt;
    }
};

/*
legendre's formula

Meaning: It counts how many factors of the prime p are in n! by adding the count of numbers divisible by p, plus an extra factor for those divisible by p², and so on.

set p as 5
*/