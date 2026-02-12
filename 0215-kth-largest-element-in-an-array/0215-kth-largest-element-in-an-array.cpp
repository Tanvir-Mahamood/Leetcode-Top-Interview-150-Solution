class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if(k <= n/2) {
            priority_queue<int> heap; // Max heap
            for(int num: nums) {
                heap.push(num);
            }
            k -= 1;
            while(k--) {
                heap.pop();
            }
            return heap.top();
        }
        else {
            priority_queue<int, vector<int>, greater<int>> heap; // Min Heap
            for(int num: nums) {
                heap.push(num);
            }
            k = n - k;
            while(k--) {
                heap.pop();
            }
            return heap.top();
        }
        return -1; // never happens
    }
};