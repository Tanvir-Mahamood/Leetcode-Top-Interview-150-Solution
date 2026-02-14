class Solution {
private:
    double slop_calc(int x1, int y1, int x2, int y2) {
        if(x1 == x2) return INT_MAX;
        else return (double)(y2 - y1) / (x2 - x1);
    }

public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        for(auto it1: points) {
            int x1 = it1[0], y1 = it1[1];
            map<double, int> mp;
            for(auto it2: points) {
                if(it1 == it2) continue;
                int x2 = it2[0], y2 = it2[1];
                double slope = slop_calc(x1, y1, x2, y2);
                mp[slope]++;
                ans = max(ans, mp[slope]);
            }
        }
        return ans + 1;
    }
};