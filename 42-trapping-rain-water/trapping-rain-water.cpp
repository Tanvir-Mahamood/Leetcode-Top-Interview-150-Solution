class Solution {
public:
    int trap(vector<int>& height) {
        int i, n = height.size(), minn = 0, maxx = 0, ans = 0;
        vector<int> left(n), right(n);
        for (i = 0; i < n; i++) {
            minn = max(minn, height[i]);
            left[i] = minn;
        }
        for (i = n - 1; i >= 0; i--) {
            maxx = max(maxx, height[i]);
            right[i] = maxx;
        }
        // for(i=0; i<n; i++) cout << left[i] << " "; cout << nn;
        // for(i=0; i<n; i++) cout << right[i] << " "; cout << nn;
        for (i = 0; i < n; i++)
            ans += (min(left[i], right[i]) - height[i]);
        return ans;
    }
};