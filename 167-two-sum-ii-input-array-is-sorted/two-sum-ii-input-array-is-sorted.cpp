class Solution {
public:
    int bs(vector<int> &arr, int val, int forbidden_idx) {
        int n = arr.size();
        int begg = 0, endd = n - 1;

        while(begg <= endd) {
            int midd = (begg + endd) / 2;
            if(midd == forbidden_idx) {
                if(midd < n-1) midd += 1;
                else midd -= 1;
            }
            if(arr[midd] == val) return midd;
            if(val < arr[midd]) endd = midd - 1;
            else if(val > arr[midd]) begg = midd + 1;
        } 
        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        int i, n = numbers.size(), idx1, idx2 = -1;
        vector<int> temp(n);

        for(i=0; i<n; i++) {
            idx1 = i;
            idx2 = bs(numbers, target-numbers[i], idx1);
            if(idx2 != -1) {
                break;
            }
        }
        vector<int> ans(2);
        ans[0] = idx1 + 1;
        ans[1] = idx2 + 1;

        return ans;
    }
};