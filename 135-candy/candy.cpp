class Solution {
public:
    int candy(vector<int>& ratings) {
        ios::sync_with_stdio(false); cin.tie(0);
        
        int i, n = ratings.size(), sum = 0;
        vector<int> candies(n, 1);

        // if it domenates on its left neighbour
        for(i=1; i<n; i++) {
            if(ratings[i] > ratings[i-1]) candies[i] = candies[i-1] + 1;
        } 

        // if it domenates on its right neighbour
        for(i=n-2; i>=0; i--) {
            if(ratings[i] > ratings[i+1]) candies[i] = max(candies[i] ,candies[i+1] + 1);
        } 

        for(i=0; i<n; i++) sum += candies[i];

        return sum;
    }
};