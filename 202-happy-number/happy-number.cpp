class Solution {
public:
    int nextNumber(int n) {
        int sum = 0;
        while(n) {
            int r = n % 10;
            sum += r * r;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = nextNumber(slow);
            fast = nextNumber(nextNumber(fast));
        } while(slow != fast);

        return slow == 1;
    }
};



// Floyd Cycle Detection
/*

#include <bits/stdc++.h>
using namespace std;

// Compute sum of squares of digits from a string
string nextNumber(const string &num) {
    long long sum = 0;
    for(char c : num) {
        int d = c - '0';
        sum += 1LL * d * d;
    }
    return to_string(sum);
}

// Floyd Cycle Detection
bool isHappy(string num) {
    string slow = num;
    string fast = num;

    do {
        slow = nextNumber(slow);               // move 1 step
        fast = nextNumber(nextNumber(fast));   // move 2 steps
    } while (slow != fast);

    return slow == "1";
}

int main() {
    string n;
    cin >> n;

    if (isHappy(n))
        cout << "Happy Number\n";
    else
        cout << "Not a Happy Number\n";

    return 0;
}

*/

/*
Why Floyd Cycle Detection?

Happy numbers eventually fall into a cycle.
If the number is happy → sequence reaches 1
If not happy → sequence falls into a cycle that does not include 1
You don’t need a set to store visited numbers, saving memory.

Why It Works for Large Numbers?
Even if the number is extremely large (e.g., 10^20000):
The first sum-of-digits operation reduces it drastically.
After 1–2 steps, the number becomes small (< 1000), so operations are constant-time.
To support very large numbers, we take input as a string.


Even for large input:

Each sum operation: O(k), where k = digits initially
After first 2 steps: number becomes small (< 1000)
Cycle detection steps: O(1)
*/