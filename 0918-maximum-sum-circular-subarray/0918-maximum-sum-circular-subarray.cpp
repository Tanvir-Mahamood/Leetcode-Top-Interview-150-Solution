class Solution {
public:
    int kadaneMax(vector<int>& nums) { // default kadane's algorithm
        int maxSum = -INT_MAX, currSum = 0;
        for(int num: nums) {
            currSum += num;
            maxSum = max(maxSum, currSum);
            if(currSum < 0) currSum = 0;
        }
        return maxSum;
    }

    int kadaneMin(vector<int>& nums) {
        int minSum = INT_MAX, currSum = 0;
        for(int num : nums) {
            currSum += num;
            minSum = min(minSum, currSum);
            if(currSum > 0) currSum = 0; // reset if positive
        }
        return minSum;
    }


    int ArraySum(vector<int>& nums) {
        int sum = 0;
        for(int num: nums) {
            sum += num;
        }
        return sum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSubArraySum = kadaneMax(nums);
        int minSubArraySum = kadaneMin(nums);
        int arraySum = ArraySum(nums);

        int maxCircularSubArraySum = arraySum - minSubArraySum;

        if(maxSubArraySum < 0) return maxSubArraySum;
        return max(maxSubArraySum, maxCircularSubArraySum);
    }
};

/*
Non-circular subarray => Kadane's algorithm to find maximum sub array sum
Circular subarray => Modified Kadane's Algorithm to find minimum subarray sum.
*/