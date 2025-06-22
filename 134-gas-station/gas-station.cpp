class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        ios::sync_with_stdio(false); cin.tie(0);
        
        int i, totalGas = 0, totalCost = 0, n = gas.size(), index = 0;
        for(i=0; i<n; i++) totalGas += gas[i];
        for(i=0; i<n; i++) totalCost += cost[i];

        if(totalGas < totalCost) return -1;

        totalGas = 0;
        for(i=0; i<n; i++) {
            totalGas += gas[i] - cost[i];
            if(totalGas < 0) {
                totalGas = 0;
                index = i+1;
            }
        }

        return index;
    }
};