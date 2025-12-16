class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int i , n = points.size(), cnt= 1;
        vector<int> common(2), point(2);
        common = points[0];

        for(i=1; i<n; i++) {
            point = points[i];

            if(common[1] >= point[0]) {
                common = {max(common[0], point[0]), min(common[1], point[1])};
            }
            else {
                cnt++;
                common = point;
            }
        }

        return cnt;
    }
};