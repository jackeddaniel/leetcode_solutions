class Solution {
    public:
        int twoCitySchedCost(vector<vector<int>>& costs) {

            sort(costs.begin(), costs.end(), [](auto &x, auto &y) {
                    return (x[0] - x[1]) < (y[0] - y[1]);
                    }
                );

            int n = costs.size()/2;

            int cost = 0;

            for(int i = 0; i < n; i++ ) {
                cost += costs[i][0];
                cost += costs[i+n][1];
            }
            return cost;

        }
};
