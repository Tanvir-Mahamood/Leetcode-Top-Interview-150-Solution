class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, sum = 0;
        while(l <= r) {
            sum = max(sum, (r-l)*min(height[l], height[r]));
            if(height[l] < height[r]) l += 1;
            else if(height[l] > height[r]) r -= 1;
            else if(height[l] == height[r]) l += 1, r -= 1;
        }
        return sum;
    }
};