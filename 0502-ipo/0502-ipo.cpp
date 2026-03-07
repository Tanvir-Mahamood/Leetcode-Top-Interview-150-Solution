class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        // Min Heap for capitals
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minCapital;

        // Max Heap for profit
        priority_queue<int> maxProfit;

        for(int i=0; i<n; i++) {
            minCapital.push({capital[i], profits[i]});
        }

        for(int i=0; i<k; i++) {
            // Add all affordable projects
            while(!minCapital.empty() && minCapital.top().first <= w) {
                maxProfit.push(minCapital.top().second);
                minCapital.pop();
            }

            // There is no affordable projects
            if(maxProfit.empty()) {
                break;
            }

            // Do the most profitable project
            w += maxProfit.top();
            maxProfit.pop();
        }
        return w;
    }
};