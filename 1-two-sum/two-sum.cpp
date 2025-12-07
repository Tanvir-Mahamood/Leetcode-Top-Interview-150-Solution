class Solution {
public:
    int binarySearch(vector<pair<int, int>> &arr, int target) {
        int left = 0, right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;  
            if (arr[mid].first == target) return arr[mid].second;              
            else if (arr[mid].first < target) left = mid + 1;           
            else right = mid - 1;         
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        int i, n = nums.size(), token, idx1 = -1, idx2 = -1;
        vector<pair<int, int>> numbers(n);
        for(i=0; i<n; i++) numbers[i] = {nums[i], i};
        sort(numbers.begin(), numbers.end());

        for(i=0; i<n; i++) {
            token = target - numbers[i].first;
            idx1 = numbers[i].second;
            if(token != numbers[i].first) idx2 = binarySearch(numbers, token); 
            else idx2 = (i + 1 < n && numbers[i].first == numbers[i+1].first) ? numbers[i+1].second : -1;

            if(idx2 != -1) break;
        }
        vector<int> result = {idx1, idx2};
        return result;
    }
};